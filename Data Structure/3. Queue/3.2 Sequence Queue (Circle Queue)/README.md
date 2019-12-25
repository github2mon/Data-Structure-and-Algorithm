* 为更好理解，我们规定，队头指针指向队头元素的前一个数组元素位置，队尾指针始终指向队尾元素
* `if(head == tail)`, 该队列即为空队列
* 初始化空顺序队列时，`head = tail = -1`
* 当`tail == MaxSize - 1`时，队列可能发生“假溢出”  
`head = (head + 1) % MaxSize`  
`tail = (tail + 1) % MaxSize`
* 为了与队列判空条件`head == tail`相区别，使用`(tail + 1) % MaxSize == head`作为队列判满条件，但会浪费一个存储单元，即tail指到head前一位为满，但head位为空
