#include "ffmsg_queue.h"
#include "easylogging++.h"
extern "C" {
#include "libavutil/avstring.h"
#include "libavutil/eval.h"
#include "libavutil/mathematics.h"
#include "libavutil/pixdesc.h"
#include "libavutil/imgutils.h"
#include "libavutil/dict.h"
#include "libavutil/parseutils.h"
#include "libavutil/samplefmt.h"
#include "libavutil/avassert.h"
#include "libavutil/time.h"
#include "libavformat/avformat.h"
#include "libavdevice/avdevice.h"
#include "libswscale/swscale.h"
#include "libavutil/opt.h"
#include "libavcodec/avfft.h"
#include "libswresample/swresample.h"
}

#include "ffmsg.h"

FFmsg_Queue::FFmsg_Queue()
{

}

void FFmsg_Queue::msg_free_res(AVMessage *msg)
{
    
}
//写入数据到队列
int FFmsg_Queue::msg_queue_put_private(MessageQueue *q, AVMessage *msg)
{   
    AVMessage *msg1;
    if(q->abort_request)
    {
        return -1;
    }
    msg1 = q->recycle_msg;
    if(msg1)
    {
        q->recycle_msg = msg1->next;//典型的头插法
        q->recycle_count++;
    }
    else
    {
        q->alloc_count++;
        msg1 = (AVMessage *)av_malloc(sizeof(AVMessage));
    }

    *msg1 = *msg;
    msg1->next = NULL;

    if(!q->first_msg) {
        q->first_msg = msg1;
    } else {
        q->last_msg->next = msg1;
    }

    q->last_msg = msg1;
    q->nb_messages++;
    SDL_CondSignal(q->cond);
    return 0;
}

int FFmsg_Queue::msg_queue_put(MessageQueue *q, AVMessage *msg)
{
    //加锁
    SDL_LockMutex(q->mutex);
    int ret = msg_queue_put_private(q, msg);
    SDL_UnlockMutex(q->mutex);
    return ret;
}

void FFmsg_Queue::msg_init_msg(AVMessage *msg)
{
    memset(msg, 0, sizeof(AVMessage));

}

void FFmsg_Queue::msg_queue_put_simple1(MessageQueue *q, int what)
{
    AVMessage msg;
    msg_init_msg(&msg);
    msg.what = what;
    msg_queue_put(q, &msg);

}

void FFmsg_Queue::msg_queue_put_simple2(MessageQueue *q, int what, int arg1)
{
    AVMessage msg;
    msg_init_msg(&msg);
    msg.what = what;
    msg.arg1 = arg1;
    msg_queue_put(q, &msg);

}

void FFmsg_Queue::msg_queue_put_simple3(MessageQueue *q, int what, int arg1, int arg2)
{
    AVMessage msg;
    msg_init_msg(&msg);
    msg.what = what;
    msg.arg1 = arg1;
    msg.arg2 = arg2;
    msg_queue_put(q, &msg);
}

void FFmsg_Queue::msg_obj_free_l(void *obj)
{
    
}

void FFmsg_Queue::msg_queue_put_simple4(MessageQueue *q, int what, int arg1, int arg2, void *obj, int obj_len)
{
    
}
//step1 init msg queue
void FFmsg_Queue::msg_queue_init(MessageQueue *q)
{
    memset(q, 0, sizeof(MessageQueue));
    q->mutex = SDL_CreateMutex();
    q->cond = SDL_CreateCond();
    // q->abort_request = 1;//中断标志
}

void FFmsg_Queue::msg_queue_flush(MessageQueue *q)
{
    
}

void FFmsg_Queue::msg_queue_destroy(MessageQueue *q)
{
    
}

void FFmsg_Queue::msg_queue_abort(MessageQueue *q)
{
    
}

void FFmsg_Queue::msg_queue_start(MessageQueue *q)
{
    SDL_LockMutex(q->mutex);
    q->abort_request = 0;

    AVMessage msg;
    msg_init_msg(&msg);
    msg.what = FFP_MSG_FLUSH;
    msg_queue_put_private(q, &msg);
    SDL_UnlockMutex(q->mutex);
}

int FFmsg_Queue::msg_queue_get(MessageQueue *q, AVMessage *msg, int block)
{   

    AVMessage *msg1;
    int ret;

    SDL_LockMutex(q->mutex);

    for(;;) {
        if(q->abort_request) {
            ret = -1;
            break;
        }
        //获取消息
        msg1 = q->first_msg;
        if(msg1) {
            q->first_msg = msg1->next;
            if(!q->first_msg)
                q->last_msg = NULL;
            q->nb_messages--;
            *msg = *msg1;
            msg1->obj = NULL;
            msg1->next = q->recycle_msg;
            q->recycle_msg = msg1;
            ret =1;
            break;      // 记得这里有个break的
        } else if (!block) {
            ret = 0;
            break;
        } else {
            SDL_CondWait(q->cond, q->mutex);
        }
    }
    SDL_UnlockMutex(q->mutex);




    return ret;

}

void FFmsg_Queue::msg_queue_remove(MessageQueue *q, int what)
{
    
}

void FFmsg_Queue::show_queue_info(MessageQueue *q)
{   
    LOG(TRACE) << "msg_queue_get: " << q->nb_messages;
    LOG(TRACE) << "msg_queue_get: " << q->alloc_count;

    for(int i = 0; i < q->nb_messages; i++)
    {
        LOG(TRACE) << "printf: " << q->first_msg->what << "arg1: " << q->first_msg->arg1 << "arg2: " << q->first_msg->arg2;
        q->first_msg = q->first_msg->next;
    }

}
