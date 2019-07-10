linux 

###### 实验1 Linux 系统简介

安装程序

```shell
sudo apt-get update
sudo apt-get install <name>
```

##### 实验2 基本概念及操作

Linux 用户管理

linux 是一个可以实现多用户登录的操作系统，比如 A 和 B 可以同时登陆通一台主机，他们共享主机资源，也分别有自己的用户空间，存放各自文件。由于Linux 的**用户管理**和**权限机制**，不同用户之间不可以轻易查看、修改彼此文件。

###### 快捷键

| 按键     | 作用                     |
| -------- | ------------------------ |
| ctrl + a | 光标移至输入行头 Home    |
| ctrl + e | 光标移至输入行尾 End     |
| ctrl + k | 删除从光标所在位置到行尾 |



历史输入命令： `pg up   ↑`

###### Shell 常用通配符

| 字符                    | 含义                                           |
| ----------------------- | ---------------------------------------------- |
| *                       | 匹配 0 或多个字符                              |
| ?                       | 匹配任意一个字符                               |
| [list]                  | 匹配 list 中的任意单一字符                     |
| [^list]                 | 匹配 list 中的任意单一字符以外的字符           |
| [c1-c2]                 | 匹配 c1-c2 中的任意单一字符，如：`[0-9]`,[a-z] |
| {string1, string2, ...} | 匹配 string1 或 string2 (...) 其一**字符串**   |
| {c1..c2}                | 匹配 c1-c2 中全部字符 如{1..10}                |

一次创建多个文件：比如： "love_1_linux.txt, love_2_linux.txt, ... love_10_linux.txt"

```shell
$ touch love_{1..10}_shiyanlou.txt
```



###### 获取帮助

**man** 

 是 `Manual pages` 的缩写， 调用手册页, 分为8个区段, 分别从 1~ 8 来标识（查看相应区段，在man 后面加上相应数字即可）

1 ：一般命令,   2 ：系统调用, 3 ：库函数，涵盖C标准函数库

```
$ man <command_name>
```

在 `man` 中使用搜索：`/<你要搜的关键字>`

`n` 切换下一个关键字;  `shift + n`为上一个关键字

`Space` 翻页  `Enter` 向下滚动一行 或 `K,J`  (vim)

`q` 退出

**-- help 参数**

```shell
$ ls --help
```



##### 实验3 用户及文件权限管理

###### 查看用户

```shell
$ who am i
$ who mom likes
```

###### 创建用户

`su <user>`  切换到用户 user

`sudo <cmd> `  以特权级别运行 cmd 命令, 需要当前用户属于 sudo 组

`sudo - <user>`  切换用户，同时改变环境变量  -> 好像和 `sudo -l <user>` 一样

`sudo addusesr <username>`   新建用户

###### 用户组

`groups <user>`  查看用户属于哪个用户组

新建用户如不指定用户组，默认创建一个与用户名相同的用户组

**将用户添加到用户组**

```shell
$ sudo usermod -G <groupname> <username>   
```

**删除用户**

```shell
$ sudo deluser <username> --remove-home
```



###### linux 文件权限

**查看文件权限**

使用较长格式列出文件

```shell
$ ls -l
```

![](https://doc.shiyanlou.com/linux_base/3-9.png/wm)

![](https://raw.githubusercontent.com/zhanyeye/Figure-bed/img/img/20190709133321.png)

**变更文件所有者**

将文件的的所有者设为user, 用户组设置为group

```shell
$ chown user[:group] file...
```

**修改文件权限**

![](https://raw.githubusercontent.com/zhanyeye/Figure-bed/img/img/20190709135026.png)

+ 二进制数字表示

  ```shell
  $ chmod --- <file name>    --- 分别代表
  example:
  $ chmod 600 test.text  只有拥有者有读写能力
  ```

+ 加减赋值操作

  ```shell
  $ chmod [g,o,u][+,-][r,w,x] <file name> 
  example:
  $ chmod go-rw iphone6   
  g, o, u  表示 group, others, user
  +, - 表示增加和去掉相应的权限
  ```

  

##### 实验4 Linux 目录结构及文件基本操作

![](https://doc.shiyanlou.com/linux_base/4-1.png/wm)

