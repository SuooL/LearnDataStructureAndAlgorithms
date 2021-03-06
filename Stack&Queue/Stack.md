# 顺序栈
## 定义和基本概念

栈是限定在表尾进行插入和删除的线性表
并将可以删除和插入的一端称为栈顶，另一端为栈尾，空栈是指不含任何元素的栈。栈的特点是“后进先出的线性表”，栈的插入成为进栈，删除称为出栈。

## 栈的抽象数据类型定义

```cpp
ADT Stack

Data
  和线性表具有相同的元素类型，相邻的元素具有前驱和后继的关系。

Operation :
  InitSatck(*S) : 初始化栈操作
  DestroyStack(*S) : 若栈存在，则销毁之
  ClearStack(*S) : 将栈清空
  StackEmpty(S) : 判断栈是否为空
  GetTop(S, *e) : 获取栈顶元素
  Push(*S, e) : 向存在的栈中插入元素e
  Pop(*S, e) : 删除存在栈的站定元素，并将其返回
  StackLength(S) : 获取栈的元素个数

EndADT
```

## 要点

1. 栈空的时候栈顶指针为-1
2. 进栈的时候现将栈顶指针加一，然后更新栈顶元素，出栈的时候直接将栈顶指针减一即可
3. 顺序栈的空间有限，决定栈的长度是栈顶指针的位置


- 顺序栈的实现参见 [OrderStack.c](./OrderStack.c)

## 两栈共享空间

两个相同数据类型元素的顺序栈共享空间，合成一个栈

- 两栈共享栈的实现参见 [DoubleStack.c](./DoubleStack.c)


# 链栈
## 定义和基本概念

链栈即栈的链式存储实现。

具有链表和栈的双重特点，即是只能在一端进行插入和删除操作，但是摆脱了传统栈空间的限制。

其插入和删除也和链表的操作一样，只不过链表的节点结构是栈的结构。

## 要点

1. 操作的时候注意参数的类型，是指针类型还是值类型，对应的操作符也不相同。其中如果是对链栈存储做更改则必须要是指针，即引用类型的参数，如果不需要对链栈做更改，则可以传入值类型的参数。

2. 同时注意在创建新的链栈节点的时候，其节点结构的类型。

3. 插入或删除的之后，对链栈的长度参数也应该作相应的更改。

4. 对链栈的数据存储做更改的时候，时刻记得检查链栈是否为空。

- 链栈的实现见 [LinkStack.c](./LinkStack.c)

# 栈的应用

## 递归

栈的应用之一就是递归算法。

### 递归示例 —— 裴波那契数列的实现

其循环实现和递归实现的代码见 [Fibonacci.c](./Fibonacci.c)

### 递归示例 —— 四则运算表达式的实现（整数）

借助栈的实现是后缀表示法，即是逆波兰表达式。之所以称之为后缀是因为所有的运算符号都是要在要运算的数字后面的。

那么我们平时使用的表达式则是中缀表达式，如何将中缀表达式转换为后缀表达式呢？

转换的规则是：从左到右遍历中缀表达式的每个字符和数字，如是数字就输出，即成为后缀表达式的一部分，如是符号先判断他和栈顶元素的优先级，如果是右括号或者优先级不大于栈顶符号，则栈顶元素依次出栈并输出，并将当前符号进栈，最终输出完整的后缀表达式。

整个运算的规则是：对一个后缀表达式，从左向右遍历其每个数字和符号，遇到数字的话就进栈，遇到符号的话，就将处于栈顶的两个数字出栈，进行运算，运算的结果进栈，直到获取最终结果。

因此整个运算的过程是两步，现将中缀表达式转换为后缀，然后对后缀进行运算。
















