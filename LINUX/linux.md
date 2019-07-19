linux 

##### 实验1 Linux 系统简介

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

###### FHS 标准

![](https://doc.shiyanlou.com/linux_base/4-1.png/wm)

+ 输入命令时：连续2次 `tab` 会显示所有可能的情况

###### 文件操作

新建空白文件：**touch**

+ 主要用来更改已有文件的时间戳（如：最近访问时间，和修改时间）
+ 若只指定一个文件名的，则创建一个空白文件（不会覆盖已有同名文件）

新建目录：**mkdir**

+ 可以创建一个空目录，也可以同时指定创建目录的权限属性
+  `-p`参数： 如果不存在父目录：同时创建一个多级目录

复制文件：**cp** 

`cp [options] source dest `

+ `-r` 参数：递归复制，复制目录时使用

删除文件：**rm**

+ 强制删除 `rm -f <file name>`
+ 删除目录（递归删除）`rm -r <filename>`

移动文件和重命名：**mv**

+ 移动文件：`mv 原目录文件 目的目录`
+ 重命名文件：`mv 旧的文件名 新的文件名`
+ 批量重命名使用： `rename`

###### 查看文件

**cat, tac**

打印文件内容到标准输出，cat 正序显示，tac 倒序

+ `-n` 显示行号 

**nl** 添加行号并打印

**more** 和 **less** 分页查看文件

+ Enter 向下一行
+ Space 下滚动一屏
+ h 帮助，q 退出

**head** 和 **tail** 命令 

+ 默认看前10行或后10行，可以指定行数，－n 1(只看１行)

查看文件类型：**file**



##### 实验5 环境变量与文件查找

shell中创建一个变量

`declare tmp`  其实也可以不用 declare 预声明一个变量，直接即用即创建

`tmp=shiyanlou`

 读取变量的值`echo`

```
$ echo $tmp
```

$ 符号，用于表示引用一个变量的值

###### 环境变量

> 环境变量的作用域比自定义变量的要大，如 Shell 的环境变量作用于自身和它的子进程。在所有的 UNIX 和类 UNIX 系统中，每个进程都有其各自的环境变量设置，且默认情况下，当一个进程被创建时，除了创建过程中明确指定的话，它将继承其父进程的绝大部分环境设置。

通常我们会涉及到的变量类型有三种：

- 当前 Shell 进程私有用户自定义变量，如上面我们创建的 tmp 变量，只在当前 Shell 中有效。
- Shell 本身内建的变量。
- 从自定义变量导出的环境变量。

也有三个与上述三种环境变量相关的命令：`set`，`env`，`export`。这三个命令很相似，都是用于打印环境变量信息，区别在于涉及的变量范围不同。详见下表：

| 命 令    | 说 明                                                        |
| -------- | ------------------------------------------------------------ |
| `set`    | 显示当前 Shell 所有变量，包括其内建环境变量（与 Shell 外观等相关），用户自定义变量及导出的环境变量。 |
| `env`    | 显示与当前用户相关的环境变量; 还可以让命令在指定环境中运行。 |
| `export` | 显示从 Shell 中导出成环境变量的变量; 也能通过它将自定义变量导出为环境变量。 |

 关于哪些变量是环境变量，可以简单地理解成在当前进程的子进程有效则为环境变量，否则不是（有些人也将所有变量统称为环境变量，只是以全局环境变量和局部环境变量进行区分，我们只要理解它们的实质区别即可）。我们这里用 `export` 命令来体会一下，先在 Shell 中设置一个变量 `temp=shiyanlou`，然后再新创建一个子 Shell 查看 `temp` 变量的值：

 ![](https://doc.shiyanlou.com/document-uid735639labid60timestamp1532339293501.png/wm)

**永久生效**

> 但是问题来了，当你关机后，或者关闭当前的 shell 之后，环境变量就没了啊。怎么才能让环境变量永久生效呢？

按变量的生存周期来划分，Linux 变量可分为两类：

1. 永久的：需要修改配置文件，变量永久生效；
2. 临时的：使用 export 命令行声明即可，变量在关闭 shell 时失效。

这里介绍两个重要文件 `/etc/bashrc`（有的 Linux 没有这个文件） 和 `/etc/profile` ，它们分别存放的是 shell 变量和环境变量。还有要注意区别的是每个用户目录下的一个隐藏文件：

```
.profile 可以用 ls -a 查看
cd /home/shiyanlou
ls -a 
```

这个 .profile 只对当前用户永久生效。而写在 `/etc/profile` 里面的是对所有用户永久生效，所以如果想要添加一个永久生效的环境变量，只需要打开 `/etc/profile`，在最后加上你想添加的环境变量就好啦。

###### 命令的查找路径与顺序

> 我们在 Shell 中输入一个命令，Shell 是怎么知道去哪找到这个命令然后执行的呢？这是通过环境变量 `PATH` 来进行搜索的，熟悉 Windows 的用户可能知道 Windows 中的也是有这么一个 PATH 环境变量。这个 `PATH` 里面就保存了 Shell 中执行的命令的搜索路径。
>
> 当我们在 Shell 中执行一个命令时，系统就会按照 PATH 中设定的路径按照顺序依次到目录中去查找，如果存在同名的命令，则执行先找到的那个。

**创建shell脚本**

```shell
$ cd /home/shiyanlou
$ touch hello_shell.sh
$ gedit hello_shell.sh
```

在脚本中添加如下内容，保存并退出（**注意不要省掉第一行，这不是注释，论坛有用户反映有语法错误，就是因为没有了第一行**）：

```shell
#!/bin/bash

for ((i=0; i<10; i++));do
    echo "hello shell"
done

exit 0
```

为文件添加可执行权限：

```shell
$ chmod 755 hello_shell.sh
```

执行脚本：

```shell
$ cd /home/shiyanlou
$ ./hello_shell.sh
```

如何做到像使用系统命令一样执行自己创建的脚本文件或者程序呢？那就要将命令所在路径添加到 `PATH` 环境变量了。

###### 添加自定义路径到“ PATH ”环境变量

 在前面我们应该注意到 `PATH` 里面的路径是以 `:` 作为分割符的，所以我们可以这样添加自定义路径：

```
$ PATH=$PATH:/home/shiyanlou/mybin
```

**注意这里一定要使用绝对路径。**

现在你就可以在任意目录执行那个命令了（注意需要去掉前面的 `./`）。你可能会意识到这样还并没有很好的解决问题，因为我给 PATH 环境变量追加了一个路径，它也只是在当前 Shell 有效，我一旦退出终端，再打开就会发现又失效了。有没有方法让添加的环境变量全局有效？或者每次启动 Shell 时自动执行上面添加自定义路径到 PATH 的命令？下面我们就来说说后一种方式——让它自动执行。

在每个用户的 home 目录中有一个 Shell 每次启动时会默认执行一个配置脚本，以初始化环境，包括添加一些用户自定义环境变量等等。zsh 的配置文件是 `.zshrc`，相应 Bash 的配置文件为 `.bashrc` 。它们在 `etc` 下还都有一个或多个全局的配置文件，不过我们一般只修改用户目录下的配置文件。

我们可以简单地使用下面命令直接添加内容到 `.zshrc` 中：

```
$ echo "PATH=$PATH:/home/shiyanlou/mybin" >> .zshrc
```

**上述命令中 >> 表示将标准输出以追加的方式重定向到一个文件中，注意前面用到的 > 是以覆盖的方式重定向到一个文件中，使用的时候一定要注意分辨。在指定文件不存在的情况下都会创建新的文件。**

###### 修改和删除已有变量

 

**变量修改**

变量的修改有以下几种方式：

| 变量设置方式                   | 说明                                         |
| ------------------------------ | -------------------------------------------- |
| `${变量名#匹配字串}`           | 从头向后开始匹配，删除符合匹配字串的最短数据 |
| `${变量名##匹配字串}`          | 从头向后开始匹配，删除符合匹配字串的最长数据 |
| `${变量名%匹配字串}`           | 从尾向前开始匹配，删除符合匹配字串的最短数据 |
| `${变量名%%匹配字串}`          | 从尾向前开始匹配，删除符合匹配字串的最长数据 |
| `${变量名/旧的字串/新的字串}`  | 将符合旧字串的第一个字串替换为新的字串       |
| `${变量名//旧的字串/新的字串}` | 将符合旧字串的全部字串替换为新的字串         |

比如要修改我们前面添加到 PATH 的环境变量。为了避免操作失误导致命令找不到，我们先将 PATH 赋值给一个新的自定义变量 path：

```
$ path=$PATH
$ echo $path
$ path=${path%/home/shiyanlou/mybin}
# 或使用通配符,*表示任意多个任意字符
$ path=${path%*/mybin}
```

**变量删除**

可以使用 `unset` 命令删除一个环境变量：

```
$ unset temp
```



######  如何让环境变量立即生效

前面我们在 Shell 中修改了一个配置脚本文件之后（比如 zsh 的配置文件 home 目录下的 `.zshrc`），每次都要退出终端重新打开甚至重启主机之后其才能生效，很是麻烦，我们可以使用 `source` 命令来让其立即生效，如：

```
$ cd /home/shiyanlou
$ source .zshrc
```

`source` 命令还有一个别名就是 `.`，上面的命令如果替换成 `.` 的方式就该是：

```
$ . ./.zshrc
```

在使用`.`的时候，需要注意与表示当前路径的那个点区分开。

注意第一个点后面有一个空格，而且后面的文件必须指定完整的绝对或相对路径名，source 则不需要。

###### 搜索文件

 与搜索相关的命令常用的有 `whereis`，`which`，`find` 和 `locate` 。

- **whereis 简单快速**

  这个搜索很快，因为它并没有从硬盘中依次查找，而是直接从数据库中查询。`whereis` 只能搜索**二进制文件**`-b`，**man 帮助文件**`-m`和**源代码文件**`-s`。

```
$ whereis who
$ whereis find
```

- **locate 快而全**

通过“ /var/lib/mlocate/mlocate.db ”数据库查找，不过这个数据库也不是实时更新的，系统会使用定时任务每天自动执行 `updatedb` 命令更新一次，所以有时候你刚添加的文件，它可能会找不到，需要手动执行一次 `updatedb` 命令（在我们的环境中必须先执行一次该命令）。它可以用来查找指定目录下的不同文件类型，如查找 /etc 下所有以 sh 开头的文件：

```
$ sudo apt-get update
$ sudo apt-get install locate
$ locate /etc/sh
```

> **注意，它不只是在 /bin 目录下查找，还会自动递归子目录进行查找。**

查找 /usr/share/ 下所有 jpg 文件：

```
$ locate /usr/share/\*.jpg
```

> **注意要添加 \* 号前面的反斜杠转义，否则会无法找到。**

如果想只统计数目可以加上 `-c` 参数，`-i` 参数可以忽略大小写进行查找，whereis 的 `-b`、`-m`、`-s` 同样可以使用。

- **which 小而精**

`which` 本身是 Shell 内建的一个命令，我们通常使用 `which` 来确定是否安装了某个指定的软件，因为它只从 `PATH` 环境变量指定的路径中去搜索命令：

```
$ which man
```

- **find 精而细**

`find` 应该是这几个命令中最强大的了，它不但可以通过文件类型、文件名进行查找而且可以根据文件的属性（如文件的时间戳，文件的权限等）进行搜索。`find` 命令强大到，要把它讲明白至少需要单独好几节课程才行，我们这里只介绍一些常用的内容。

这条命令表示去 /etc/ 目录下面 ，搜索名字叫做 interfaces 的文件或者目录。这是 find 命令最常见的格式，千万记住 find 的第一个参数是要搜索的地方：

```
$ sudo find /etc/ -name interfaces
```

> **注意 find 命令的路径是作为第一个参数的， 基本命令格式为 `find [path][option] [action] `。**



##### 实验６　文件打包与解压缩 

**zip：**
打包 ：zip something.zip something （目录请加 -r 参数）

+ -r, 参数表示递归打包包含子目录的全部内容，
+ -q, 参数表示为安静模式，即不向屏幕输出信息，
+ -o, 表示输出文件，需在其后紧跟打包输出文件名
+ -9 ~ -1, 设置压缩级别为 9 和 1（9 最大，1 最小），重新打包
+ -e 参数可以创建加密压缩包
+ -l, 参数将 `LF` 转换为 `CR+LF` 

解包：unzip something.zip

+ 指定路径：-d 参数

**tar：**
打包：tar -cf something.tar something

+ -c, 表示创建一个 tar 包文件，
+ -f, 用于指定创建的文件名，注意文件名必须紧跟在 `-f` 参数之后

解包：tar -xf something.tar

+ -x, 解包一个文件

+ 指定路径：-C 参数
+ -t, 只查看不解包文件
+ 现在我们要使用其它的压缩工具创建或解压相应文件只需要更改一个参数即可：
  + *.tar.gz	-z
  	 *.tar.xz	-J
  	 tar.bz2	-j



##### 实验７　文件系统操作与磁盘管理

###### 查看磁盘和目录的容量

**df**  查看磁盘的容量

+ -h 友好的显示大小

  ![](https://raw.githubusercontent.com/zhanyeye/Figure-bed/deepin-pic/imgDeepinScreenshot_select-area_20190718104510.png)

**du** 查看目录的容量

+ -h 友好的显示大小

+ -d 指定查看目录的深度

  ```
  # 只查看1级目录的信息
  $ du -h -d 0 ~
  # 查看2级
  $ du -h -d 1 ~
  ```

###### 简单的磁盘管理

**dd 命令简介**

`dd`命令用于转换和复制文件，不过它的复制不同于`cp`。之前提到过关于 Linux 的很重要的一点，**一切即文件**，在 Linux 上，硬件的设备驱动（如硬盘）和特殊设备文件（如`/dev/zero`和`/dev/random`）都像普通文件一样，只是在各自的驱动程序中实现了对应的功能，dd 也可以读取文件或写入这些文件。

`dd`的命令行语句与其他的 Linux 程序不同，因为它的命令行选项格式为`选项=值`，而不是更标准的`--选项 值`或`-选项=值`。`dd`默认从标准输入中读取，并写入到标准输出中，但可以用选项`if`（input file，输入文件）和`of`（output file，输出文件）改变。

我们先来试试用dd命令从标准输入读入用户的输入到标准输出或者一个文件中：

```shell
# 输出到文件
$ dd of=test bs=10 count=1 # 或者 dd if=/dev/stdin of=test bs=10 count=1
# 输出到标准输出
$ dd if=/dev/stdin of=/dev/stdout bs=10 count=1
# 注
在打完了这个命令后，继续在终端打字，作为你的输入
```

+ `bs`（block size）用于指定块大小（缺省单位为 Byte，也可为其指定如'K'，'M'，'G'等单位）

+ `count`用于指定块数量

  > 如果，我指定只读取总共 10 个字节的数据，当我输入了“hello shiyanlou”之后加上空格回车总共 16 个字节（一个英文字符占一个字节）内容，显然超过了设定大小。使用`du`和`cat`命令看到的写入完成文件实际内容确实只有 10 个字节（那个黑底百分号表示这里没有换行符）,而其他的多余输入将被截取并保留在标准输入。



**使用 dd 命令创建虚拟镜像文件**

从`/dev/zero`设备创建一个容量为 256M 的空文件：

```shell
$ dd if=/dev/zero of=virtual.img bs=1M count=256
$ du -h virtual.img
```



**使用 mkfs 命令格式化磁盘（我们这里是自己创建的虚拟磁盘镜像）**

我们可以简单的使用下面的命令来将我们的虚拟磁盘镜像格式化为`ext4`文件系统：

```shell
$ sudo mkfs.ext4 virtual.img
```



**使用 mount 命令挂载磁盘到目录树**

> 用户在 Linux/UNIX 的机器上打开一个文件以前，包含该文件的文件系统必须先进行挂载的动作，此时用户要对该文件系统执行 mount 的指令以进行挂载。该指令通常是使用在 USB 或其他可移除存储设备上，而根目录则需要始终保持挂载的状态。又因为 Linux/UNIX 文件系统可以对应一个文件而不一定要是硬件设备，所以可以挂载一个包含文件系统的文件到目录树。
>
> Linux/UNIX 命令行的 mount 指令是告诉操作系统，对应的文件系统已经准备好，可以使用了，而该文件系统会对应到一个特定的点（称为挂载点）。挂载好的文件、目录、设备以及特殊文件即可提供用户使用。

我们先来使用`mount`来查看下主机已经挂载的文件系统：

```shell
sudo mount
```

> 输出的结果中每一行表示一个设备或虚拟设备,每一行最前面是设备名，然后是 on 后面是挂载点，type 后面表示文件系统类型，再后面是挂载选项（比如可以在挂载时设定以只读方式挂载等等）。

那么我们如何挂载真正的磁盘到目录树呢，`mount`命令的一般格式如下：

```shell
mount [options] [source] [directory]
```

一些常用操作：

```
mount [-o [操作选项]] [-t 文件系统类型] [-w|--rw|--ro] [文件系统源] [挂载点]
```

现在直接来挂载我们创建的虚拟磁盘镜像到`/mnt`目录：

```
$ mount -o loop -t ext4 virtual.img /mnt 
# 也可以省略挂载类型，很多时候 mount 会自动识别

# 以只读方式挂载
$ mount -o loop --ro virtual.img /mnt
# 或者mount -o loop,ro virtual.img /mnt
```

**使用 umount 命令卸载已挂载磁盘**



##### 实验8　Linux下的帮助命令

###### 内建命令与外部命令

> **内建命令**实际上是 shell 程序的一部分，其中包含的是一些比较简单的 Linux 系统命令，这些命令是写在bash源码的builtins里面的，由 shell 程序识别并在 shell 程序内部完成运行，通常在 Linux 系统加载运行时 shell 就被加载并驻留在系统内存中。而且解析内部命令 shell 不需要创建子进程，因此其执行速度比外部命令快。比如：history、cd、exit 等等。

> **外部命令**是 Linux 系统中的实用程序部分，因为实用程序的功能通常都比较强大，所以其包含的程序量也会很大，在系统加载时并不随系统一起被加载到内存中，而是在需要时才将其调入内存。虽然其不包含在 shell 中，但是其命令执行过程是由 shell 程序控制的。外部命令是在 Bash 之外额外安装的，通常放在/bin，/usr/bin，/sbin，/usr/sbin等等。比如：ls、vi等。

type 命令来区分命令是内建的还是外部的

```
#得到这样的结果说明是内建命令，正如上文所说内建命令都是在 bash 源码中的 builtins 的.def中
xxx is a shell builtin
#得到这样的结果说明是外部命令，正如上文所说，外部命令在/usr/bin or /usr/sbin等等中
xxx is /usr/bin/xxx
#若是得到alias的结果，说明该指令为命令别名所设定的名称；
xxx is an alias for xx --xxx
```

**help 命令**

help 命令是用于显示 shell 内建命令的简要帮助信息

外部命令基本上都有一个参数--help,这样就可以得到相应的帮助

**man 命令**

例如`man ls`

我们会发现最左上角显示“ LS （1）”，在这里，“ LS ”表示手册名称，而“（1）”表示该手册位于第一章节。这个章节又是什么？在 man 手册中一共有这么几个章节

| 章节数 | 说明                                               |
| ------ | -------------------------------------------------- |
| `1`    | Standard commands （标准命令）                     |
| `2`    | System calls （系统调用）                          |
| `3`    | Library functions （库函数）                       |
| `4`    | Special devices （设备说明）                       |
| `5`    | File formats （文件格式）                          |
| `6`    | Games and toys （游戏和娱乐）                      |
| `7`    | Miscellaneous （杂项）                             |
| `8`    | Administrative Commands （管理员命令）             |
| `9`    | 其他（Linux特定的）， 用来存放内核例行程序的文档。 |

**info 命令**

> 得到的信息比 man 还要多了，info 来自自由软件基金会的 GNU 项目，是 GNU 的超文本帮助系统，能够更完整的显示出 GNU 信息。所以得到的信息当然更多

```
# 安装 info
$ sudo apt-get update
$ sudo apt-get install info
# 查看 ls 命令的 info
$ info ls
```



#####  实验9　Linux任务计划crontab

###### crontab 简介

crontab 命令用于设置周期性被执行的指令。

> crontab 命令从输入设备读取指令，并将其存放于 crontab 文件中，以供之后读取和执行。通常，crontab 储存的指令被守护进程激活，crond 为其守护进程，crond 常常在后台运行，每一分钟会检查一次是否有预定的作业需要执行。
>
> 通过 crontab 命令，我们可以在固定的间隔时间执行指定的系统指令或 shell　script 脚本。时间间隔的单位可以是分钟、小时、日、月、周的任意组合。

crontab 的格式

```
# Example of job definition:
# .---------------- minute (0 - 59)
# |  .------------- hour (0 - 23)
# |  |  .---------- day of month (1 - 31)
# |  |  |  .------- month (1 - 12) OR jan,feb,mar,apr ...
# |  |  |  |  .---- day of week (0 - 6) (Sunday=0 or 7) OR sun,mon,tue,wed,thu,fri,sat
# |  |  |  |  |
# *  *  *  *  * user-name command to be executed
```

添加一个计划任务

```shell
crontab -e
```

我们通过这样的一个例子来完成一个任务的添加，在文档的最后一排加上这样一排命令,该任务是每分钟我们会在/home/shiyanlou目录下创建一个以当前的年月日时分秒为名字的空白文件

```shell
*/1 * * * * touch /home/shiyanlou/$(date +\%Y\%m\%d\%H\%M\%S)
```

> 注意 “ % ” 在 crontab 文件中，有结束命令行、换行、重定向的作用，前面加 ” \ ” 符号转义，否则，“ % ” 符号将执行其结束命令行或者换行的作用，并且其后的内容会被做为标准输入发送给前面的命令。

添加成功后我们会得到最后一排 installing new crontab 的一个提示

指令来查看我们添加了哪些任务 `crontab -l`

虽然我们添加了任务，但是如果 cron 的守护进程并没有启动，它根本都不会监测到有任务，当然也就不会帮我们执行，我们可以通过以下2种方式来确定我们的 cron 是否成功的在后台启动，默默的帮我们做事，若是没有就得执行`sudo cron －f &`

```shell
ps aux | grep cron

or

pgrep cron
```

当我们并不需要这个任务的时候我们可以使用这么一个命令去删除任务

```shell
crontab -r
```



###### crontab 的深入

每个用户使用 `crontab -e` 添加计划任务，都会在 `/var/spool/cron/crontabs` 中添加一个该用户自己的任务文档，这样目的是为了隔离。

 如果是系统级别的定时任务，应该如何处理？只需要以 sudo 权限编辑 `/etc/crontab` 文件就可以。

cron 服务监测时间最小单位是分钟，所以 cron 会每分钟去读取一次 /etc/crontab 与 /var/spool/cron/crontabs 里面的內容。 

在 /etc 目录下，cron 相关的目录有下面几个：

![](https://raw.githubusercontent.com/zhanyeye/Figure-bed/deepin-pic/imgDeepinScreenshot_select-area_20190718224433.png)

每个目录的作用：

1. /etc/cron.daily，目录下的脚本会每天执行一次，在每天的6点25分时运行；
2. /etc/cron.hourly，目录下的脚本会每个小时执行一次，在每小时的17分钟时运行；
3. /etc/cron.monthly，目录下的脚本会每月执行一次，在每月1号的6点52分时运行；
4. /etc/cron.weekly，目录下的脚本会每周执行一次，在每周第七天的6点47分时运行；

系统默认执行时间可以根据需求进行修改。



##### 实验10 命令执行顺序控制与管道

###### 有选择的执行命令

`&&` 就是用来实现选择性执行的，它表示如果前面的命令执行结果（不是表示终端输出的内容，而是表示命令执行状态的结果）返回0则执行后面的，否则不执行

`|| `表示逻辑或，同样 Shell 也有一个`||`，它们的区别就在于，shell中的这两个符号除了也可用于表示逻辑与和或之外，就是可以实现这里的命令执行顺序的简单控制。`||`在这里就是与`&&`相反的控制效果，当上一条命令执行结果为≠0($?≠0)时则执行它后面的命令

 可以从`$?`环境变量获取上一次命令的返回结果

```shell
which cowsay>/dev/null && echo "exist" || echo "not exist"
```

###### 管道

它表现出来的形式就是将前面每一个进程的输出(stdout)直接作为下一个进程的输入(stdin)。

 ```shell
$ ls -al /etc | less
 ```

###### cut命令,打印每一行的某个字段

打印`/etc/passwd`文件中以`:`为分隔符的第1个字段和第6个字段分别表示用户名和其家目录：

```shell
$ cut /etc/passwd -d ':' -f 1,6
```

+ -d --delimiter=DELIM    :  use DELIM instead of TAB for field delimiter
+ --fields=LIST : select  only  these fields;  also print any line that contains no delimiter character, unless the -s option is specified

打印`/etc/passwd`文件中每一行的前/? N个字符：

```shell
# 前五个（包含第五个）
$ cut /etc/passwd -c -5
# 前五个之后的（包含第五个）
$ cut /etc/passwd -c 5-
# 第五个
$ cut /etc/passwd -c 5
# 2到5之间的（包含第五个）
$ cut /etc/passwd -c 2-5
```

###### grep命令,在文本中或stdin中查找匹配字符串

`grep`命令的一般形式为：

```shell
grep [命令选项]... 用于匹配的表达式 [文件]...
```

我们搜索`/home/shiyanlou`目录下所有包含"shiyanlou"的文本文件，并显示出现在文本中的行号：

```shell
$ grep -rnI "shiyanlou" ~
```

`r` 参数表示递归搜索子目录中的文件,`-n`表示打印匹配项行号，`-I`表示忽略二进制文件

也可以在匹配字段中使用正则表达式，下面简单的演示：

```shell
# 查看环境变量中以"yanlou"结尾的字符串
$ export | grep ".*yanlou$"
# 其中$就表示一行的末尾。
```

###### wc 命令，简单小巧的计数工具

wc 命令用于统计并输出一个文件中行、单词和字节的数目，比如输出`/etc/passwd`文件的统计信息：

```shell
$ wc /etc/passwd
  38   62 2254 /etc/passwd
```

分别只输出行数、单词数、字节数、字符数和输入文本中最长一行的字节数：

```shell
# 行数
$ wc -l /etc/passwd
# 单词数
$ wc -w /etc/passwd
# 字节数
$ wc -c /etc/passwd
# 字符数
$ wc -m /etc/passwd
# 最长行字节数
$ wc -L /etc/passwd
```

###### sort 排序命令

 默认为字典排序：

```shell
$ cat /etc/passwd | sort
```

反转排序：

```shell
$ cat /etc/passwd | sort -r
```

按特定字段排序：

```shell
$ cat /etc/passwd | sort -t':' -k 3
# 上面的-t参数用于指定字段的分隔符，这里是以":"作为分隔符；-k 字段号用于指定对哪一个字段进行排序

# 如果要按照数字排序就要加上-n参数：
$ cat /etc/passwd | sort -t':' -k 3 -n
```

###### uniq 去重命令

 uniq命令只能去连续重复的行，不是全文去重, 可以先排序,在去重

```shell
$ history | cut -c 8- | cut -d ' ' -f 1 | sort | uniq
# 或者
$ history | cut -c 8- | cut -d ' ' -f 1 | sort -u
```

