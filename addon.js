const { readFile, writeFile } = require('./src/native/build/Release/addon.node');
const buf = Buffer.from('Hello world!');
// File path can change to what you want
const filePath = 'D:/addon.txt';

// Create a file named addon.txt
writeFile(filePath, buf);
const content = readFile(filePath);
// Reading file content, content is buffer type
console.log(content);

