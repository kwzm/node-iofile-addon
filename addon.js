const  { readFile, writeFile } = require('./build/Release/addon.node')

const binaryFilePath = 'd:\\Users\\w13269464702\\Desktop\\pic.jpg'
const textFilePath = 'd:\\Users\\w13269464702\\Desktop\\text.txt'
const outputBinaryFilePath = 'd:\\Users\\w13269464702\\Desktop\\new.jpg'
const outputTextFilePath = 'd:\\Users\\w13269464702\\Desktop\\outputText.txt'
const binaryContent = readFile(binaryFilePath)
const textContent = readFile(textFilePath)

// console.log("binary content: ", binaryContent)
// console.log("text content: ", textContent)

writeFile(outputBinaryFilePath, binaryContent)
writeFile(outputTextFilePath, textContent)