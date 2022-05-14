async function readInput() {
    return new Promise( (resolve) => {
        process.stdin.once("data", (data) => {
            resolve(data.toString().replace("\r", "").replace("\n", ""));
        });
    });
}


async function main() {
    process.stdout.write("Write the number1: ");
    var number1 = parseInt(await readInput());

    process.stdout.write("Write the number2: ");
    var number2 = parseInt(await readInput());
    
    console.log(`${number1} + ${number2} = ${number1+number2}`);

    process.exit(0);
}

main();