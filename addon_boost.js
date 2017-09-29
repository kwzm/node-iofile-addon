const { readFile, writeFile } = require('./src/boost/build/Release/addon.node');
const buf = Buffer.from('Hello world!');
// File path can change to what you want
const filePath = 'D:/addon_boost.txt';

// Create a file named addon.txt
writeFile(filePath, buf);
const content = readFile(filePath);
// Reading file content, content is buffer type
console.log(content);