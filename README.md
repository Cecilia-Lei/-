# Carrot-Fantasy
### 同济大学 2024程序设计范式大作业
## 项目信息
* 项目选题 ： 保卫萝⼘
* 项目成员 ：刘夏、雷思雨
## 项目开发文档
* 选用引擎： Cocos2d-x v4.0
* 辅助软件：Tiled-1.1.4、TexturePackerGUI
* 小组分工：
    - 刘夏
        - 游戏关卡架构及类设计
        - 基本游戏逻辑实现
        - 地图制作，部分游戏关卡素材制作
  
    - 雷思雨
        - 游戏UI界面制作
        - 游戏背景音乐与音效功能制作
        - 防御塔建造、升级与出售功能实现
        - 游戏暂停功能制作  

*  评分项完成度
    -  基础功能
         - [x] ⽀持防御塔和防御塔的删除
         - [x] 需要每种防御塔的攻击特效，⾄少要完成发射物弹道
         - [x] 怪物、萝⼘⽣命值显示
         - [x] ⽀持资源功能，资源可⽤于购买防御塔，资源可通过击杀怪物获得
         - [x] ⽀持每种防御塔的升级，⾄少可升级2次
         - [x] ⽀持⾄少3种怪物
         - [x] ⽀持⾄少2张地图
         - [x] ⽀持背景⾳乐
         - [x] 需要关卡选择界⾯和保存通关进度记录功能（即已完成哪些关卡，可进⾏哪些关卡，哪些关卡还需解锁）

    - 可选功能
        - [x] ⽀持特殊技能，如AOE/单体伤害技能或增益技能
        - [x] 暂停游戏功能
        - [x] ⽀持中途退出时记录当前状态，下次进⼊同⼀关卡继续上⼀次游戏进程的功能
        - [x] ⽀持攻击、建造、击杀时的⾳效
  
     -   C++新特性
         - [x] 类型推断
         - [x] 基于范围的for循环
         - [x] 智能指针
         - [x] Lambda表达式
   
    - 其他亮点 
         - [x] 游戏还原度高
            - 除地图建造外，全部使用原版游戏素材
            - 还原原版界面设计
       
         - [x] 使用json数据文件
            - 记录关卡数据：怪物数据、炮塔数据、路径、可建造区域等，增强了数据的可读性和可修改性。
            - 记录存档，保存当前关卡数据

* 开发时遇到的问题
    - Tiled版本过高导致Tiled地图无法加载到cocos2dx-v4，需要降低Tiled版本
    - cocos2dx-v4中在Windows环境下加载csv编码的Tiled地图由BUG，通过修改cocos2dx引擎源码解决， 后来发现可以修改Tiled地图的编码格式。
        ```cpp
        #if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
			// Fix bug when tilemap data is in csv format.
			// We have to remove all '\r' from the string
			currentString.erase(std::remove(currentString.begin(), currentString.end(), '\r'), currentString.end());
        #endif
        ``` 
 


## 游戏文档

### 游戏简介
同保卫萝卜
### 游戏截图
#### 单机模式
* 主界面
* <img src="MDres\1.png" width = "300" height = "200" alt="" align=center />
* 选择关卡
* <img src="MDres\2.png" width = "300" height = "200" alt="" align=center />
* 游戏关卡界面
* <img src="MDres\3.png" width = "300" height = "200" alt="" align=center />
* 游戏结束界面
* <img src="MDres\4.png" width = "300" height = "200" alt="" align=center />
* <img src="MDres\6.png" width = "300" height = "200" alt="" align=center />





