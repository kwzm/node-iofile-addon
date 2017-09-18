#include <fstream>
#include <iostream>
#include <string>
#include <nan.h>
using namespace std;

NAN_METHOD(readFile) {
  if (!info[0]->IsString()) {
    Nan::ThrowTypeError("File name need string");
    return;
  }

  Nan::Utf8String sFileName(info[0]);

	// 要读入整个文件，必须采用二进制打开   
	ifstream inputFileStr (*sFileName, ios::binary);

	if (!inputFileStr) {
    Nan::ThrowTypeError("File open error");
    return;
  }

	 //获取文件长度
	inputFileStr.seekg (0, inputFileStr.end);
	int length = inputFileStr.tellg();
	inputFileStr.seekg (0, inputFileStr.beg);

	// 分配内存空间  
	char * buffer = new char [length];

	cout << "Reading " << length << " characters... " << endl;

	// read data as a block:
  inputFileStr.read (buffer,length);

	if (inputFileStr) {
		cout << "all characters read successfully." << endl;
	} else {
  	cout << "error: only " << inputFileStr.gcount() << " could be read";
	} 

	inputFileStr.close();

	info.GetReturnValue().Set(Nan::NewBuffer(buffer, (unsigned)length).ToLocalChecked());
}

NAN_METHOD(writeFile) {
	if (!info[0]->IsString()) {
    Nan::ThrowTypeError("File name need string");
    return;
  }

	if (!node::Buffer::HasInstance(info[1])) {
    Nan::ThrowTypeError("Content need buffer");
    return;
  }

	Nan::Utf8String sFileName(info[0]);
	char *buffer = node::Buffer::Data(info[1]->ToObject());
	size_t size = node::Buffer::Length(info[1]);
	ofstream outputFileStr (*sFileName, ios::binary);

	if (!outputFileStr) {
    Nan::ThrowTypeError("File open error");
    return;
  }

	outputFileStr.write(buffer, size);

	outputFileStr.close();
}

NAN_MODULE_INIT(Init) {
  NAN_EXPORT(target, readFile);
	NAN_EXPORT(target, writeFile);
}

NODE_MODULE(addon, Init)