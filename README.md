# node-iofile-addon
A node c++ addon to I/O file. Just a example to learn how to write c++ addon.

## Usage

Install dependences

```bash
$ npm install
```

####Native

``` bash
$ const { readFile, writeFile } = require('./src/native/build/Release/addon.node');
$ const buffer = readFile('filePath');

$ writeFile('filePath', buffer);
```

#### Boost

Install boost and compile boost lib

```bash
$const { readFile, writeFile } = require('./src/boost/build/Release/addon.node');
$ const buffer = readFile('filePath');

$ writeFile('filePath', buffer);
```

## API

1、Buffer readFile(string filePath)

2、void writeFile(string filePath, Buffer content)

## Notice

Node addon is compiled in x64, boost lib either.

If your platform is x86 , you need to recompile.