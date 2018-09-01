#define MAX_COUNT 5  //����������
static char proc_buffer[MAX_COUNT]; //����������
static int empty_flag = 0;  //�Ƿ�Ϊ�գ�0��ʾΪ��
static int last_r_pos = 0;
static int mymsg_r = 0; //��λ��
static int mymsg_w = 0; //дλ��

/* �ж��Ƿ�Ϊ�� */
static int is_empty_mymsg(void)
{
    if(((mymsg_w % MAX_COUNT)  == (mymsg_r % MAX_COUNT)) && (empty_flag == 0)){
        return 1;   //Is empty
    }

    return 0;   //Is not empty
}

/* �ж��Ƿ�Ϊ�� */
static int is_full_mymsg(void)
{
    if(((mymsg_w % MAX_COUNT) == (mymsg_r % MAX_COUNT)) && (empty_flag != 0)){
        return 1;   //Is full
    }

    return 0;   //Is not full
}

/* ��ȡһ���ֽ� */
 int read_onebyte_mymsg(char *buf_p)
{
    if(is_empty_mymsg()){
        return 0;   //empty buffer can't read
    }

    *buf_p = proc_buffer[mymsg_r % MAX_COUNT];
    mymsg_r = (mymsg_r + 1) % MAX_COUNT;
    empty_flag --;  //ÿ��ȡһ���ֽڿձ�־��ȥ1

    return 1;
}

/* д��һ���ֽ� */
 void write_onebyte_mymsg(char byte)
{
    proc_buffer[mymsg_w % MAX_COUNT] = byte;
    if(is_full_mymsg()){
        mymsg_r = (mymsg_r + 1) % MAX_COUNT;
        empty_flag --;
    }

    mymsg_w = (mymsg_w + 1) % MAX_COUNT;
    empty_flag ++;  //ÿд��һ���ֽڣ��ձ�־��һ
}