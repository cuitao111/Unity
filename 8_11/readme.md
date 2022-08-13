代码优化 Player使用状态机实现

VS 快速重写 VA助手

同一时间只能播放一个动画 

player enemy能否共用一套FSM

声明FSM控制器 参数

添加命名空间

跳跃时无法转向：通过input 更新水平速度 
水平转向是如何实现？

攻击后无法操作 Invoke的问题:
通过info 能否实现：可以实现但是不如Invoke流畅

碰撞体的Trigger如果设置为True 则不会有碰撞体积

滑铲时头部的碰撞器失效：
parameter中定义头部碰撞器headCollider
可以直接将当前对象的组件拖拽到 public参数中

不执行起身动作，一直回检测到碰撞体 Overlap 没有设置layer

headCollider设置enbled失败，将OnUpdate中逻辑注释掉之后就可以
问题在于检测不到碰撞体，执行else语句时 会直接切换到Stand状态


属性应该何时使用？

OnCollider2D无法使用Compare判断：查看Fox 被青蛙击中的情况
角色碰撞检测到的一直时ground，无法检测 bullet 或enemy 提高player位置即可
角色不会调用OnCollisionEnter2D 会一直弹反子弹
使用子弹的OnTriggerEnter2D

没有调用Hit 状态名为Hurt  会发生抖动 

使用状态机播放完一次动画后不会返回初始State ，需要使用info进度来转换

第一播放完动画，直接卡住：
原因为下面两句的顺序
parameter.animator.Play("Hurt");
parameter.isHit = true;
先播放动画，由于bullet和player的位置很近，还是会调用bullet的OnTrigger2D
由于此时没有设置isHit，因此还是会调用，TransState(Hit) info > 1
还是会卡住：原因为 info的值一直大于1
解决方法：GetHit接口中将isHit=true的语句删掉
还是不行：bullet中只设置isHit为true，在所有状态前判断一下是否进入Hit状态，构建AnyState-》hit

被攻击时，给定一个受击方向相反的速度

需要滑行一段，现在滑行时间太短

流畅连击



爬墙、蹬墙跳
https://www.bilibili.com/video/BV14d4y1N7ox?spm_id_from=333.999.0.0&vd_source=1f4a7a119cba75354caa87a52ab8737c

1. Player脚本
检测是否在墙体上：
定义Vector wallOffset 用于获取Player左右两侧
wallLayer保存墙体所在层 ground？
public bool isleftWall ,rightwall 用于判断例子效果
定义函数 WallCheck 判断是否在墙上
isleft = Physics2D.OverlapCircle(Player左侧， 0.1f, wallLyaer) 

2. 绘制出左右两侧
OnDrawGizmos()
Gizmos.color = color.red
Gizmos.DrawWireSphere 绘制两个圆

3. 写爬墙代码
if(按下LeftShift &&(isLeftWall || isRightWall)) isWallMove = true
else

4. 枚举值  WallGrab 抓住 WallSlide 下滑 WallClimb爬墙 WallJump蹬墙跳
WallGrab抓墙体 前置条件 Jump Fall
rb.grabityScale = 0f;
rb.velocity = Vector2.zero;

rb.grabityScale 该对象受重力影响的程度。

5. 创建2D的Physics Material

6. input_y
上 climb 下 Slide
设置rb.velocity = new Vector2(rb.velocity.x ,10 或 -13);

跳跃手感：
高跳乘数highJumpMultiplier和低跳乘数lowJumpMultiplier float
if(Input.GetKeyDown(KeyCode.Space)){
    rb.vel = jumpForce * 10;
}
if(vel.y < 0){
    //高跳下落，块
    rb.vel = Vector2.up * Physics2D.gravity.y * (highJumpMultiplier - 1) * Time.deltaTime
}else if(rb.vel.y > 0 && !Input.GetKey(KeyCode.Space)){
    上升过程中,松开Space
    rb.vel = Vector2.up * Physics2D.gravity.y * (lowJumpMultiplier - 1) * Time.deltaTime
}

low增加，最低高度减少
high增加下落速度增加

跳跃时扒墙的瞬间如果按墙的反方向