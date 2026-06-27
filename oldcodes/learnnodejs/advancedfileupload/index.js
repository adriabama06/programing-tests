const express = require('express');
const fs = require('fs');
const path = require('path');
const formidableMiddleware = require('express-formidable');
//const formidable = require('formidable');

const app = express();

const events = [
  {
    event: 'fileBegin',
    action: async (req, res, next, name, file) => {console.log("begin file: "+file.name);},
  }, 
  {
    event: 'field',
    action: async (req, res, next, name, value) => { /* your callback */ },
  },
  {
    event: 'file',
    action: async (req, res, next, name, value) => { /*console.log(value)*/ },
  },
];

app.use(formidableMiddleware({
    multiples: false,
    encoding: 'utf-8', 
    uploadDir: path.join(__dirname, `uploads`),
    maxFileSize: 8000 * 1024 * 1024,
    //multiples: true, // req.files to be arrays of files
}, events));
app.use(express.static(path.join(__dirname)));

app.get('/', async (req, res) => {
    if(req.get('host').startsWith('secret')) {
        res.send('Shh es secreto')
    } else {
        res.sendFile(path.join(__dirname, `public\\index.html`));
    };
});

app.post('/file-upload', async (req, res) => {

    //var newPath = `${__dirname}\\uploads\\${req.files.upload.name}`;

    /*const form = new formidable.IncomingForm();

    form.parse(req, async (err, fields, files) => { 
  
        var oldPath = files.upload.path; 
        var rawData = fs.readFileSync(oldPath);
      
        fs.writeFile(newPath, rawData, async (err) => {
            if(err) console.log(err) 
            return res.send("Successfully uploaded");
        });
    });*/

    fs.readFile(req.files.upload.path, async (err, data) => {
        if(err) console.log(err);
        fs.writeFile(`./uploads/${req.files.upload.name}`, data, async (err) => {
            if(err) console.log(err);
            fs.unlink(req.files.upload.path, async (err) => {
                if(err) console.log(err);
            });
            res.redirect('/');
        });
    });

});

app.listen(3000, async () => {
    console.log(`Server start at http://localhost:3000`);
});