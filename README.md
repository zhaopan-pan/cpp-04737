## 背景
学习笔记

## 版本
c++ 程序设计 04737  
刘振安

## 开发环境
- OS:win10 64bit
- 编辑器:vscode
- 依赖插件(环境):C/C++,C/C++ Compile Run,C++ Intellisense,Clang-format
- 运行插件:Code Run
### Code Run配置：
  code run直接运行会把编译后文件直接输出到当前目录，文件一多容易比较混乱，打开设置，在设置中搜索`coderun`,在`setting.json`文件中找到code-runner.executorMap配置项，给C、C++配置以下命令可以将编译后的文件输出到指定文件夹，然后配置你的`.gitignore`文件，不论是写代码还是提交代码，有木有感觉清爽很多呢？
### window:
```c++
"cpp": "$path=-join ($dir,'\\.output-file');$exist=Test-Path $path;if ($exist -eq $False) {mkdir $path};cd $dir;$outpath=-join ($path,'/$fileNameWithoutExt'); g++ -std=c++11 $fileName -o $outpath;  ;if ($?){./.output-file/$fileNameWithoutExt}",
```

### Mac
```sh
paths=$workspaceRoot/.output-file; if test ! -e $paths; then; mkdir $paths; fi; cd $dir && gcc $fileName -o $paths/$fileNameWithoutExt && mv $dir/$fileName $paths && $paths/$fileNameWithoutExt
```
