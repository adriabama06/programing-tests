const mysql = require('mysql');
async function sleep(ms) {
  return new Promise((resolve) => {
    setTimeout(resolve, ms);
  });
}
/*interface createData {
    name: String;
    columnas: Number;
    nombres: Array;
    tipo: Array;
    limite: Array;
}*/

module.exports = class {
    constructor(host, user, pass, db) {
        this.connection = mysql.createConnection({
            host: `${host}`,
            user: `${user}`,
            password: `${pass}`,
	        database: `${db}`
        });
    }
    tables = {
        create: async (name, data) => {

            const sql = `CREATE TABLE \`${name}\` ( ${data} ) ENGINE = InnoDB;`;

            this.connection.query(sql, async (err, result) => {

                if (err) throw err;

            });

        },
        delete: async () => {

        },
        is: async (basededatos, tabla, columna) => {

            var r;

            const sql = `SELECT * FROM ${basededatos}.${tabla} WHERE \`${columna}\`;`;

            this.connection.query(sql, async (err, result) => {
                r = true;
            });

            return r;

        },
        insert: async (table, name, data) => {
            
        },
        get: async (table, name) => {

        }
    }


    async end() {
        this.connection.end();
    }
}