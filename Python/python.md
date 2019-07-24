###### 开始python之旅

*.py 文件中 `#!/usr/bin/env python3`：

前两个字符 `#!` 称为 *Shebang* ，目的是告诉 shell 使用 Python 解释器执行其下面的代码

如果没有 `#!/usr/bin/env python3` 的话，应该使用 `python3 ×.py`来执行，否则使用 `./*.py` 程序会被当作 bash 脚本来执行，最终报错。

###### 变量和数据类型