删除当前目录下所有同名的子目录
============================
```bash
find . 
     -name   #待删除文件夹的名字
     -type d #表示类型是directory
     | xargs rm -r #获取参数并删除
```

删除空间大于or小于多少字节的文件
==============================
```bash
find . -name "*" -type f -size -10000c | xargs -n 1 rm -f # -10000c表示小于10000字节
```

批量转换png为jpg格式
===================
```bash
ls -l *.png | xargs -n 1 bash -c 'convert "$0" "${0%.png}.jpg"'
```

搜索并替换文本中的字符串
=======================
```bash
sed -i "s/oldstring/newstring/g" `grep oldstring -rl directory` # 替换directory下所有文件中oldstring为newstring
```
