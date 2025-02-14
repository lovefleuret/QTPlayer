#include "ffmsg_queue.h"
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

int FFmsg_Queue::msg_queue_put_private(MessageQueue *q, AVMessage *msg)
{
    return 0;
}

int FFmsg_Queue::msg_queue_put(MessageQueue *q, AVMessage *msg)
{
    return 0;
}

void FFmsg_Queue::msg_init_msg(AVMessage *msg)
{
    
}

void FFmsg_Queue::msg_queue_put_simple1(MessageQueue *q, int what)
{
    
}

void FFmsg_Queue::msg_queue_put_simple2(MessageQueue *q, int what, int arg1)
{
    
}

void FFmsg_Queue::msg_queue_put_simple3(MessageQueue *q, int what, int arg1, int arg2)
{
    
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
    q->abort_request = 1;//中断标志
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
    
}

int FFmsg_Queue::msg_queue_get(MessageQueue *q, AVMessage *msg, int block)
{
    return 0;
}

void FFmsg_Queue::msg_queue_remove(MessageQueue *q, int what)
{
    
}
