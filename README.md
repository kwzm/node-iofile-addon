# node-iofile-addon
A node c++ addon to I/O file. Just a example to learn how to write c++ addon.

## Usage

1、 Install dependences
``` bash
$ npm install
```

2、 Use node-gyp to compile native addon module for Node.js 
``` bash
$ node-gyp rebuild
```

3、 Import functions 
``` bash
$ const { readFile, writeFile } = require('./build/Release/addon.node');
$ const buffer = readFile('filePath');

$ writeFile(buffer, 'filePath');
```



## API

1、Buffer readFile(string filePath)

2、void writeFile(Buffer content,  string filePath)