function startdir() {
const [,, ... args] = process.argv
const { exec } = require("child_process");
exec("dir", (error, stdout, stderr) => {
  if (error) {
    console.log(`error: ${error.message}`);
    return;
}
if (stderr) {
    console.log(`stderr: ${stderr}`);
    return;
}
console.log(`stdout: ${stdout}`);
});
}
exports.startdir = startdir;