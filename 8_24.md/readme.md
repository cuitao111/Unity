VS ctrl+d 复制行
VS自动生成override方法 override+空格
VS将类移动到新文件中， Alt + Enter -> Move to
VS删除行 ctrl + L


StateMachine默认使用String初始化

PlayerMake可视化FSM状态之间的切换

Idle是一个纯C#类，如果根PlayStateMechine : MonoBehaviour打交道
在MonoBehaviour的Start中将参数传给C#类的构造函数

使用animator和代码实现人物运动及转向

动画器中设置转换的作用 idle -> walk 实际是到达监测点触发的 
fsm.StateCanExit() 和 FSM中添加状态转换的区别

Lambda返回的是一个函数

position velocity localScale

BUG1: 无法从RUN-》IDLE
RUN的onLogic中没有更新input_x
能否将input分离出来

BUG2：AddTransition不起作用
解决方法：在OnLogic中设置fsm.StateCanExit(); 丢失了解耦效果
尝试使用委托来实现值的传递


# C#委托
https://www.bilibili.com/video/BV1Q64y1i7K8/?spm_id_from=autoNext&vd_source=1f4a7a119cba75354caa87a52ab8737c
1. delegate void Help();
委托的级别较高，跟自定义类型是一个级别的
命名空间中可以放类定义和委托定义，但是不可以放变量和函数

2. 委托的实例化
类-》实例
委托类型-》委托实例 Help p;

3. 准备函数 void SayHello(){}

4. 赋值给委托实例 h = SayHello;

普通实例存放数组，委托实例存放行为
类似函数指针
委托在定义时规定了参数列表和返回值

委托作为参数进行传递
Void GoStation(Help do_sth){
    WriteLine("1");
    do_sth();
    WriteLine("1");
}

委托的简化： FUN（有返回值）通过个数来定义 Action
匿名函数的变体 Lambda表达式
GoStation(()=>WriteLine("1"));

继承了多播委托类