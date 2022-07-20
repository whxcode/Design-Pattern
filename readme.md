## 设计模式的目的  2022年 07月 17日 星期日 10:25:38 CST
  ### 代码的重用性(相同的功能代码，不用多次编写)
  ### 可读性(编成规范，便与其它人阅读和理解)
  ### 可扩展性(当新增功能；不会对原来的功能带来影响)
  ### 可靠性 
  ### 使用程序高内聚、底耦合

## 设计模式的原则
   ### 单一职责原则
       一个类；应该之负责一个职责。如果一个类有两个职责；将它拆解为两个类。
       通常在编码上，要遵守单一职责。只要在逻辑简单下，才可以违反单一职责。
       参考 0-base/03.singleResponsibly.cpp

   ### 接口隔离原则
       两个类依赖应该是最小的。

  ### 依赖倒置
     面向接口编成；不而是具体类。
     依赖的三种方式:
       A 类 依赖 B类的基类。
       1、A 类属性中有 B类；关联强。构造 A 类，必须现构造 B 类
       2、A 类的某个方法使用了 B 类；依赖性不是强；可以不用使用那个方法；也能构造 A 类。

  ### 里氏替换原则
      一个类被其它类继承后，修改这个类；可能会影响到所有之类。
      1、子类；尽量不要重写父类的方法。

  ### 开闭原则
      扩展开放、修改关闭。（针对使用方。）

  ###  迪米特法则
      将复杂的内部逻辑，封装在自己的类的类部。提供 public 方法供别人使用。降低类之间的耦合。
		  直接朋友: 成员、函数参数、函数返回值
			非直接朋友: 局部变量。


## 类与类之间的关系
	 ### 依赖
       只要在类中；使用到另外一个类；那么他们之间就存在依赖关系；如果没有对方；就不能构造自己.
       1、类的成员属性
       2、方法返回值
       3、方法的接受参数
       4、在方法中使用了局部变量。
  
	 ### 泛化(继承)
      是依赖关系的特列子，它继承了基类。
      如果 A 类继承了 B 类；那么 A、B 有繁华关系
   ### 实现 (c++中没有接口这一说法)
      如果一个接口；被一个类实现了；那么它们就是实现关系。也是依赖关系的一种特列。
   ### 关联(ralation)
      一对一
      一对多
      多对多
   ### 聚合(Aggregation)
      表示整体和部分的关系。整体可以和部分分开。
      列、电脑可以将鼠标、显示器、键盘分开。(聚合关系) 电脑与鼠标、键盘、显示器为聚合关系。
      列、电脑不可将cpu 分开(组合)
   ### 组合(composition)
      整体与部分不可分离；比如 人不能与心脏、肝 分开。

## 设计模式的分类 2022年 07月 17日 星期日 12:27:24 CST
  ### 设计模式的介绍

## 创建模式
## 1、单列模式
   在项目中；只会有一个实例。，系统内存中只存放一个对象；节省了系统资源.
## 2、简单工厂模式
  简单工厂模式，定义了一个创建对象类，由这个类封装实例的创建。
## 3、工厂方法模式
  将创建对象；抽象成方法，在由具体的子类来实现创建。
### 4、原型模式
   用原型实例；指定创建对象的种类，并且通过拷贝这些原型，创建新的对象。
### 5、建造者模式
  他可以将复杂的建造过程抽象出来，使这个抽象过程的不同实现。
  最主要是将产品与构造这个产品的流程分开。



## 结构型模式
### 6、适配器模式。
  将某个类的接口转换成客户端期望使用的结果，主要目的是为了兼容。
  如、函数参数、函数返回值。

  1、类适配器: 继承
  2、对象适配器: 聚合
  3、接口适配器: 实现一部分api、其余默认。

### 7、桥接模式。
    将实现与抽象放在两个不同的层次中，是两个层次可以独立。
    主要是组合关系，两个抽象类。

### 8、装饰器模式
  动态的将新功能附加在对象上；在对象上扩展方面11。

### 9、组合模式
Component: 这是组合中对象声明接口、实现所有类共有的默认行为、用于访问管理 Component 子组件。
Leaf: 叶子节点。 (Component)
Composite: 包含叶子节点与 Composite 节点的 子节点(Component)

