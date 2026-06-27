var mysql = require('mysql');

var guildid = '93244235';

var args = ['op!setprefix', '!']

var mysqlconnection = mysql.createConnection({
  host: "localhost",
  user: "server",
  password: "WMnY0heR3SRxPoZk",
  database: "test"
});

mysqlconnection.connect(function(err) {
  if (err) throw err;
  console.log("Conectado!");
  var sql = "CREATE TABLE prefix (discordguild VARCHAR(255), prefix VARCHAR(255))";
  mysqlconnection.query(sql, function (err, result) {
    if (err) throw err;
    console.log("Se creo la tabla");
  });
//Setea el guid id y el pefix
  if (err) throw err;
  console.log("Connected!");
  var sql = `INSERT INTO prefix (discordguild, prefix) VALUES ('${guildid}', 'op!')`;
  mysqlconnection.query(sql, function (err, result) {
    if (err) throw err;
    console.log("1 record inserted");
  });
//Update prefix
/*  if (err) throw err;
  var sql = `UPDATE prefix SET prefix = '${guildid}' WHERE prefix = '${args[1]}'`;
  mysqlconnection.query(sql, function (err, result) {
    if (err) throw err;
    console.log(result.affectedRows + " record(s) updated");
  });*/
});