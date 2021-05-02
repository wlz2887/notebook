***删除当前目录下所有同名的子目录
```bash
find . 
     -name   #待删除文件夹的名字
     -type d #表示类型是directory
     | xargs rm -r #获取参数并删除
```
