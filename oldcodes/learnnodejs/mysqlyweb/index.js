const mysql = require('mysql');
const express = require('express');
const fs = require('fs');
const path = require('path');
const app = express();

const mysqlconnection = mysql.createConnection({
    host: "localhost",
    user: "server",
    password: "WMnY0heR3SRxPoZk",
    database: "test"
});

mysqlconnection.connect();

var numero = 0;
var mysqlnum;

mysqlconnection.query(`UPDATE numerosmysql SET numer=${numero} WHERE 1`, async function (err, result, fields) {
    if (err) throw err;
});

app.get('/', async (req, res) => {
    mysqlconnection.query("SELECT numer FROM numerosmysql", async function (err, result, fields) {
        if (err) throw err;
        await console.log(parseInt(result[0].numer));
        numero = parseInt(result[0].numer);
    });
    await res.send('El numero es: ' + numero);
});
app.get('/update', async (req, res) => {
    await res.send('Se actualizo el numero');
    await numero++
    mysqlconnection.query(`UPDATE numerosmysql SET numer=${numero} WHERE 1`, async function (err, result, fields) {
        if (err) throw err;
    });
});
app.get('/reset', async (req, res) => {
    await res.send('Se seteo a 0');
    numero = 0;
    mysqlconnection.query(`UPDATE numerosmysql SET numer=${numero} WHERE 1`, async function (err, result, fields) {
        if (err) throw err;
    });
});
  
app.listen(3000, () => {
    console.log(`Estoy en el puerto http://localhost:3000`);
});
  