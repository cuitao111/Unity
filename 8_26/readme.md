# VS
VS折叠方法 Ctrl + M + O  
展开 Ctrl + M + L

UnityEngine.Events UnityEvent
可以与场景一起保存的零参数持久回调。
UnityEvent<T0> 必须重载

2DGameKit如何实现移动的逻辑：
状态机中调整mVector Update中设置移动
如何实现跳跃？

状态之间如何转换？

使用类似gamekit2D的方法实现 mMoveVector

Animator.IsInTransition
Description
Returns true if there is a transition on the given layer, false otherwise.

vector.down Vector2(0, -1)的缩写

run idle

StartCoroutine() 启动协程

public static float Clamp (float value , float min , float max );
限制value在min~max之间浮动

!Mathf.Approximately(maxHorizontalDeltaDampTime, 0f)

bool默认false

根据输入调整面向的逻辑

# Unity
animator Blend Trees 设置Mirror animation
https://www.youtube.com/watch?v=HeHvlEYpRbM

Escaping Unity Animator HELL
https://www.youtube.com/watch?v=nBkiSJ5z-hE

Physics2D.Raycast():对场景中的碰撞器投射光线。

# C#
float.Epsilon
表示大于零的最小正单值。该字段是恒定的。

BetterJumping ：直接在UpdateJumping中改即可

Idle和Run状态：
PlyaerCharacter + PlayerController（状态执行方法）
PlayerInput负责获取输入 继承InputComponent和IDataPersister
Pushable负责可推物体
LocomotionSMB 状态主函数
PersistentDataManager负责在PlayerInput中执行注册逻辑


Jump和Fall状态：
AirborneSMB
PlayerController中先不管头部的射线检测
因为涉及PhysicalHelper 和 MovePlatform 又涉及AudioSurface

MeleeAttack状态
MeleeAttackSMB
Damager.cs
Damageables.cs



# Bug
1. Idle状态VerticalSpeed的值一直跳
Time.deltaTime不稳定 锁帧 Application.targetFrameRate = 60;
VS中全局搜索 ctrl+shift+f.
IDE Rider
锁帧 Project Setting -》Qulity
QualitySettings.vSyncCount = 0;
Application.targetFrameRate = 50; 不稳定
GameKit为什么稳定
