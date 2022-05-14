const express = require('express');
const fs = require('fs');
const path = require('path');
const formidable = require('formidable');

const app = express();

app.use(express.static(path.join(__dirname)));

app.get('/', async (req, res) => {
    if(req.get('host').startsWith('secret')) {
        res.send('Shh es secreto')
    } else {
        res.sendFile(path.join(__dirname, `public\\index.html`));
    };
});

app.post('/file-upload', async (req, res) => {

    const form = new formidable.IncomingForm({
        multiples: false,
        encoding: 'utf-8',
        uploadDir: path.join(__dirname, `uploads`),
        maxFileSize: 8000 * 1024 * 1024,
        keepExtensions: true
    });

    form.parse(req, async (err, fields, files) => {
        if(err) console.log(err);
    });

/* FOR ONLY ONE FILE
    form.parse(req, async (err, fields, files) => {
        if(err) console.log(err);
        var oldPath = files.upload.path;
        var newPath = `${__dirname}\\uploads\\${files.upload.name}`;
        var rawData = fs.readFileSync(oldPath);
        fs.writeFile(newPath, rawData, async (err) => {
            if(err) console.log(err) 
            return res.send("Successfully uploaded");
        });
    });
*/

    form.on('fileBegin', async (name, file) => { //NAME = UPLOAD OR NAME IN HTML FOR THE UPLOAD
        console.log(name);
    });

    form.on('file', async (name, file) => { //NAME = UPLOAD OR NAME IN HTML FOR THE UPLOAD
        var newPath = `${__dirname}\\uploads\\${file.name}`;
        fs.rename(file.path, newPath, async (err) => {
            if(err) console.log(err);
        });
        return res.send("Successfully uploaded");
    });

});

app.listen(3000, async () => {
    console.log(`Server start at http://localhost:3000`);
});