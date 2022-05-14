package main

import (
	"fmt"
	"net/http"
	"os"
	"runtime"
	"strings"
)

const PORT string = "8080"

type formatStruct struct {
	name  string
	value string
}

func Exists(path string) bool {
	if _, err := os.Stat(path); os.IsNotExist(err) {
		return false
	}
	return true
}

func format(str string, data []formatStruct) string {
	for i := 0; i < len(data); i++ {
		var e formatStruct = data[i]
		str = strings.ReplaceAll(str, e.name, e.value)
	}
	return str
}

func sendPage(file string, dirs []string, res http.ResponseWriter, opts []formatStruct) {
	var dir = ""
	if runtime.GOOS == "windows" {
		for i := 0; i < len(dirs); i++ {
			dir += dirs[i] + "\\"
		}
	} else {
		for i := 0; i < len(dirs); i++ {
			dir += dirs[i] + "/"
		}
	}
	var f = fmt.Sprintf("%s%s", dir, file)
	if !Exists(f) {
		fmt.Println("File not found:", f)
		res.WriteHeader(404)
		res.Write([]byte("404 - Server file not found"))
		return
	}

	dat, err := os.ReadFile(f)
	if err != nil {
		panic(err)
	}
	var converted string = format(string(dat), opts)
	var tobyte []byte = []byte(converted)
	res.Write(tobyte)
}

func MainPage(res http.ResponseWriter, req *http.Request) {
	res.Header().Set("Content-Type", "text/html")
	sendPage("index.html", []string{"pages"}, res, []formatStruct{
		{
			name:  "&port&",
			value: PORT,
		},
		{
			name:  "&WebToken&",
			value: "None",
		},
	})
}

func main() {
	mux := http.NewServeMux()

	mux.HandleFunc("/", MainPage)
	//mux.Handle("/", http.FileServer(http.Dir(PathJoin([]string{"public"}))))

	server := http.Server{Addr: fmt.Sprintf("%s:%s", "0.0.0.0", PORT), Handler: mux}
	server.ListenAndServe()
}
