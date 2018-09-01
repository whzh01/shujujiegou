#define MAX_COUNT 5  //缓冲区长度
static char proc_buffer[MAX_COUNT]; //缓冲区数组
static int empty_flag = 0;  //是否为空，0表示为空
static int last_r_pos = 0;
static int mymsg_r = 0; //读位置
static int mymsg_w = 0; //写位置

/* 判断是否为空 */
static int is_empty_mymsg(void)
{
    if(((mymsg_w % MAX_COUNT)  == (mymsg_r % MAX_COUNT)) && (empty_flag == 0)){
        return 1;   //Is empty
    }

    return 0;   //Is not empty
}

/* 判断是否为满 */
static int is_full_mymsg(void)
{
    if(((mymsg_w % MAX_COUNT) == (mymsg_r % MAX_COUNT)) && (empty_flag != 0)){
        return 1;   //Is full
    }

    return 0;   //Is not full
}

/* 读取一个字节 */
 int read_onebyte_mymsg(char *buf_p)
{
    if(is_empty_mymsg()){
        return 0;   //empty buffer can't read
    }

    *buf_p = proc_buffer[mymsg_r % MAX_COUNT];
    mymsg_r = (mymsg_r + 1) % MAX_COUNT;
    empty_flag --;  //每读取一个字节空标志减去1

    return 1;
}

/* 写入一个字节 */
 void write_onebyte_mymsg(char byte)
{
    proc_buffer[mymsg_w % MAX_COUNT] = byte;
    if(is_full_mymsg()){
        mymsg_r = (mymsg_r + 1) % MAX_COUNT;
        empty_flag --;
    }

    mymsg_w = (mymsg_w + 1) % MAX_COUNT;
    empty_flag ++;  //每写入一个字节，空标志加一
}