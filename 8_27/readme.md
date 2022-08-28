Player和CharacterController2D的区别

需要查看Damager主要实现的功能

OnSLStateNoTransitionUpdate与普通Update区别何时调用

Idle->attack: 更新comboStep和MeleeAtk

attack状态：执行update逻辑且更新连击计时器

attack状态中按下攻击键： 如果在关键帧前 由于 canDamage为 true 直接返回
                        如果在关键帧之后 由于调用了

退出状态时如果添加了isAttack=false 就会掩盖掉动作

下劈是直线不是抛物线

# Bug
1. meleeDamager初始化
    直接挂到脚本组件上

2. 空中攻击和地上攻击

3. 攻击的连贯性

# C# 
属性和变量的区别


添加抓墙逻辑
注册按键
注册 Animator的Trigger
获取OnWall状态