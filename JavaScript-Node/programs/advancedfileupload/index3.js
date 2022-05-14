const express = require('express');
const fs = require('fs');
const path = require('path');
const fileupload = require('express-fileupload');

const app = express();

app.use(express.static(path.join(__dirname)));
app.use(fileupload({
    useTempFiles : true,
    tempFileDir : path.join(__dirname, 'uploads'),
    debug: true
}));

app.get('/', async (req, res) => {
    if(req.get('host').startsWith('secret')) {
        res.send('Shh es secreto')
    } else {
        res.sendFile(path.join(__dirname, `public\\index.html`));
    };
});

app.post('/file-upload', async (req, res) => {
    req.files["upload"].mv(path.join(__dirname, 'mario.rar'))
});

app.listen(3000, async () => {
    console.log(`Server start at http://localhost:3000`);
});