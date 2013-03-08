
typedef const char cchar;
typedef __int64 int64;
typedef int64 MprOff;
typedef _W64 long LONG_PTR, *PLONG_PTR;
typedef LONG_PTR SSIZE_T, *PSSIZE_T;
typedef SSIZE_T ssize;
typedef unsigned int uint;
typedef int (*MprBufProc)(struct MprBuf* bp, void *arg);
typedef ssize (*HttpFillProc)(struct HttpQueue *q, struct HttpPacket *packet, MprOff pos, ssize size);
typedef struct MprBuf {
    char            *data;              /**< Actual buffer for data */
    char            *endbuf;            /**< Pointer one past the end of buffer */
    char            *start;             /**< Pointer to next data char */
    char            *end;               /**< Pointer one past the last data chr */
    ssize           buflen;             /**< Current size of buffer */
    ssize           maxsize;            /**< Max size the buffer can ever grow */
    ssize           growBy;             /**< Next growth increment to use */
    MprBufProc      refillProc;         /**< Auto-refill procedure */
    void            *refillArg;         /**< Refill arg - must be alloced memory */
} MprBuf;
typedef struct HttpPacket {
    MprBuf          *prefix;                /**< Prefix message to be emitted before the content */
    MprBuf          *content;               /**< Chunk content */
    MprOff          esize;                  /**< Data size in entity (file) */
    MprOff          epos;                   /**< Data position in entity (file) */
    HttpFillProc    fill;                   /**< Callback to fill packet with data */
    uint            flags: 7;               /**< Packet flags */
    uint            last: 1;                /**< Last packet in a message */
    uint            type: 24;               /**< Packet type extension */
    struct HttpPacket *next;                /**< Next packet in chain */
} HttpPacket;

typedef struct MprIOVec {
    char            *start;             /**< Start of block to write */
    ssize           len;                /**< Length of block to write */
} MprIOVec;
typedef void (*HttpQueueOpen)(struct HttpQueue *q);
typedef void (*HttpQueueClose)(struct HttpQueue *q);
typedef void (*HttpQueueStart)(struct HttpQueue *q);
typedef void (*HttpQueueData)(struct HttpQueue *q, HttpPacket *packet);
typedef void (*HttpQueueService)(struct HttpQueue *q);
#define HTTP_MAX_IOVEC               16                   /**< Number of fragments in a single socket write */
typedef struct HttpQueue {
    /* Ordered for debugging */
    cchar               *name;                  /**< Queue name for debugging */
    ssize               count;                  /**< Bytes in queue (Does not include virt packet data) */
    int                 flags;                  /**< Queue flags */
    struct HttpQueue    *nextQ;                 /**< Downstream queue for next stage */
    HttpPacket          *first;                 /**< First packet in queue (singly linked) */
    struct HttpConn     *conn;                  /**< Connection owning this queue */
    ssize               max;                    /**< Advisory maxiumum queue size */
    ssize               low;                    /**< Low water mark for flow control */
    ssize               packetSize;             /**< Maximum acceptable packet size */
    HttpPacket          *last;                  /**< Last packet in queue (tail pointer) */
    struct HttpQueue    *prevQ;                 /**< Upstream queue for prior stage */
    struct HttpStage    *stage;                 /**< Stage owning this queue */
    HttpQueueOpen       open;                   /**< Open the queue */
    HttpQueueClose      close;                  /**< Close the queue */
    HttpQueueStart      start;                  /**< Start the queue */
    HttpQueueData       put;                    /**< Callback to receive a packet */
    HttpQueueService    service;                /**< Service the queue */
    struct HttpQueue    *scheduleNext;          /**< Next linkage when queue is on the service queue */
    struct HttpQueue    *schedulePrev;          /**< Previous linkage when queue is on the service queue */
    struct HttpQueue    *pair;                  /**< Queue for the same stage in the opposite direction */
    int                 servicing;              /**< Currently being serviced */
    int                 direction;              /**< Flow direction */
    void                *queueData;             /**< Stage instance data */

    /*  
        Connector instance data
     */
    MprIOVec            iovec[HTTP_MAX_IOVEC];
    int                 ioIndex;                /**< Next index into iovec */
    int                 ioFile;                 /**< Sending a file */
    MprOff              ioCount;                /**< Count of bytes in iovec including file I/O */
    MprOff              ioPos;                  /**< Position in file for sendfile */
} HttpQueue;