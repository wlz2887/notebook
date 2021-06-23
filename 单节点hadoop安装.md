要求有sudo权限emmmmmm  
```bash
sudo useradd -m hadoop -s /bin/bash // 添加用户
```
```bash
sudo passwd hadoop // 设置密码
```
```bash
sudo adduser hadoop sudo // 添加管理员权限
```
```
su hadoop // 切换至hadoop用户
```
```bash
sudo apt-get update // 更新
sudo apt-get install openssh-server // 安装ssh服务器
```
```bash
cd ~/.ssh
ssh-keygen -t rsa
cat ./id_rsa.pub >> ./authoirzed_keys // 配置免密登录
```
```bash
sudo apt-get install -y default-jdk // 安装jdk
```
```bash
cd ~/usr/local
sudo wget https://archive.apache.org/dist/hadoop/common/hadoop-2.7.0/hadoop-2.7.0.tar.gz // 下载hadoop压缩包
```
```bash
tar -zxvf hadoop-2.7.0.tar.gz // 解压缩
sudo mv ./hadoop-2.7.0/ ./hadoop // 改名
sudo chown -R hadoop ./hadoop // 修改文件权限
```
```bash
updata-alternatives --display Java // 查看java安装路径
```
编辑 ~/.bashrc
```bash
export JAVA_HOME=/usr/lib/jvm/java-11-openjdk-amd64
export HADOOP_HOME=/usr/local/hadoop
export PATH=$PATH:$HADOOP_HOME/bin
export PATH=$PATH:$HADOOP_HOME/sbin
export HADOOP_MAPRED_HOME=$HADOOP_HOME
export HADOOP_COMMON_HOME=$HADOOP_HOME
export HADOOP_HDFS_HOME=$HADOOP_HOME
export YARN_HOME=$HADOOP_HOME
export HADOOP_COMMON_LIB_NATIVE_DIR=$HADOOP_HOME/lib/native
export HADOOP_OPTS="-DJava.library.path=$HADOOP_HOME/lib"
export JAVA_LIBRARY_PATH=$HADOOP_HOME/lib/native:$JAVA_LIBRARY_PATH
```
编辑 /usr/local/hadoop/etc/hadoop/hadoop-env.sh， 在java-implementation后加入：
```bash
export JAVA_HOME=/usr/lib/jvm/java-11-openjdk-amd64
export HADOOP_CONF_DIR=/usr/local/hadoop/etc/hadoop/
```
将etc/文件拷贝至input文件夹下
```bash
mkdir input
sudo cp -r etc/* input
```
然后就可以测试examples程序了
