# 1. 软件架构（B/S架构与C/S架构，不谈移动端）

## B/S 架构软件（B代表浏览器，S代表服务器，简单来说就是浏览器向服务器发送消息，浏览器回复的一个过程） —— 我们所有的东西都希望通过网站的形式使用，而不依赖于任何其他第三方环境，且依赖于浏览器的应用，B/S会颠覆我们对软件的认识

B/S 通俗来说就是开发网站

需要注意的是网站也是软件，即Web程序，例如百度、淘宝等

C/S 架构 桌面应用

WPS

office

Adobe

随着互联网的发展，人们趋向于将C/S软件转换成B/S软件，例如office online，但有些C/S软件无法被取代，例如远程软件（系统层面）、录屏软件（无法跳出浏览器），但B/S软件缺陷在于依赖于浏览器。

如今出现云游戏，即可在浏览器上进行大型游戏，不再对硬件有较高要求，主要在于网速。

## 从就业角度考虑，B/S架构工作岗位较多

# 2. 开发B/S架构软件需要哪些人才？

## 前端（Vue、react等）

## 后端（Java/Go/Nodejs/C#(.NET)/Python/PHP 等）

## 测试（前端、数据库、渗透测试等）

## 运维（服务器、部署、运维）

## 产品经理（PM）（设计产品思路、逻辑）

## CTO（一个或多个、首席技术官、管理架构师、技术方面地位最高）

## 架构师（管理技术端部门）



# 3. 前端准备

## Vs Code（需要安装汉化、HTML、CSS、live server等插件）

## Google Chrome （考虑到兼容，有些公司使用火狐）

## Nodejs

在终端输入node后显示版本号就表示安装成功了

或输入

```shell
console.log('123')
```

输出123表示成功

设置淘宝镜像命令（可从网上找新的）：

```shell
npm install -g cnpm --registry=https://registry.npm.taobao.org
```

## Yarn（比较流行、可选）如果你要安装它，前提是必须安装Nodejs

查看当前镜像源

```shell
yarn config get registry
```

修改淘宝镜像

```shell
yarn config set registry https://registry.npm.taobao.org/
```

# 4. 前端预备课

## HTML

HTML（超文本标记语言——HyperText Markup Language，后面的数字代表版本）是构成 Web 世界的一砖一瓦，它定义了网页内容的含义、元素和结构，将网站进行内容划分。

## CSS

网页的表现与展示效果（样式、颜色、位置）

## JavaScript  (JS)

（于Java无关，其创始人想要“站在巨人的肩上”，便取名JavaScript，但他确实做到了）

功能与行为

 

## JS 框架

jQuery、 Vue、 React



## CSS 框架

bootstrap   ELEUI  。。。





# 5. 后端预备课

## 1.云服务器（大家都可以用）

## 2.VMware 虚拟机（自娱自乐）

## （两种方式二选一）

## Linux（基于Unix）基础

vim、 shell 编程、自动化、数据库、分布式（后两个不属于Linux范畴，但在Linux下运行）

**Android：   小米 OPPO 华为 VIVO ....  **

**Linux：       RedHat（商用）  Ubuntu（入门）  Kali（渗透工程师用）  ...**

Ubuntu     16.04 、18.04（版本）

Centos

……

### Desktop （桌面版，图形界面）

### Server（一般服务器用，占用资源小，提高性能，命令行界面）

开源

闭源  特殊的几个人能看见（开发组）



阿里镜像源

```shell
https://mirrors.aliyun.com/ubuntu/
```

更新（必要）

```shell
sudo apt-get update
```

设置root密码

```shell
sudo passwd root
```

安装必要软件（Node.js、yarn、Python、Git、pm2等）

```shell
sudo apt-get install openssh-server
```

1.下载 Putty（免费）

2.下载 XSell（收费）

3.ssh连接（终端）

```shell
ssh 用户名@xxx.xxx.xxx
```

（以上三选一）

**Ubuntu简单命令：**

`pwd`当前目录

ctrl+l 清屏

ctrl+u 清除当前行

`free  -m`查看占用内存

Tab键自动补全

## 后端语言：Java/Go/Nodejs/C#(.NET)/Python/PHP 

> JSP（技术，不属于Java语言、不流行、前后端不分离、不利于业务扩展、不得不学、尽快学完） -> html 里面扩展java代码 eg: <%for...%>

## HTTP服务器搭建软件：Tomcat/Nginx/Apache/pm2

Express  （初学者搭建博客）

公网IP（192.168.xxx.xxx：端口号）：网站所有人都能打开（只要服务器不关机）（IP+port）

DNS服务器解析（不是你能做到的）需要： 备案、买域名



```
yarn config set registry https://registry.yarnpkg.com
```





# MVC模式

model 模型

service 层

controller 控制器



# HTTP API



# TCP UDP

# 计算机网络

# 数据库：MySQL（关系型）/Oracle/SQL Server/SQLite/MongoDB/Redis（非关系型）

**（初学者建议先学MySQL、Redis）**

动态页面 ：和用户之间具有数据交互

CRUD：对数据的 增删改查

mysq5.7（企业一般用5.7，新版本可能收费）

https://dev.mysql.com/downloads/mysql/5.7.html

https://blog.csdn.net/weixx3/article/details/80782479

连接MySQL软件：Navicat（收费）

框架：TypeOPM、jbk等

# 6. Git（前端后端都需学、分布式版本控制软件、由林纳斯用C语言写）

1.版本控制   保留了一切的历史 可以让代码迅速恢复到你想指定的commit位置

2.协作开发

在自己的电脑上使用git，那确实是有版本控制功能，但是没有协作开发功能，协作开发需要互联网

大家把每次写的东西放到平台上，基于git的一个平台，如 GitHub，GitLab

3.如何放在Linux上部署运行、网站是怎么运行的



# 7. 全栈（基本上是四五十岁，除非天才）

# 8. Devops（开发、运维合体）

# 9. GitHub

基于Git的代码托管平台，查看各种开源软件、库

# 10. 注意休息， 尽可能不要透支身体