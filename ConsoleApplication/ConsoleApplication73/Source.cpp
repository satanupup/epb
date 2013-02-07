
#include <iostream>
using namespace std;

typedef struct HttpQueue {
    /* Ordered for debugging */

    int                 flags;                  /**< Queue flags */
    struct HttpQueue    *nextQ;                 /**< Downstream queue for next stage */
    struct HttpConn     *conn;                  /**< Connection owning this queue */
    struct HttpQueue    *prevQ;                 /**< Upstream queue for prior stage */
    struct HttpStage    *stage;                 /**< Stage owning this queue */
    struct HttpQueue    *scheduleNext;          /**< Next linkage when queue is on the service queue */
    struct HttpQueue    *schedulePrev;          /**< Previous linkage when queue is on the service queue */
    struct HttpQueue    *pair;                  /**< Queue for the same stage in the opposite direction */
    int                 servicing;              /**< Currently being serviced */
    int                 direction;              /**< Flow direction */
    void                *queueData;             /**< Stage instance data */
    /*  
        Connector instance data
     */
    int                 ioIndex;                /**< Next index into iovec */
    int                 ioFile;                 /**< Sending a file */
} HttpQueue;
typedef struct HttpConn {
    /*  Ordered for debugability */
    int             state;                  /**< Connection state */
    int             error;                  /**< A request error has occurred */
    int             connError;              /**< A connection error has occurred */
    int             pumping;                /**< Rre-entrancy prevention for httpPumpRequest() */
    struct HttpRx   *rx;                    /**< Rx object */
    struct HttpTx   *tx;                    /**< Tx object */
    HttpQueue       *readq;                 /**< End of the read pipeline */
    HttpQueue       *writeq;                /**< Start of the write pipeline */
    struct HttpQueue *serviceq;             /**< List of queues that require service for request pipeline */
    struct HttpQueue *currentq;             /**< Current queue being serviced (just for GC) */
    struct HttpEndpoint *endpoint;          /**< Endpoint object (if set - indicates server-side) */
    struct HttpHost *host;                  /**< Host object (if relevant) */
    HttpQueue       *connectorq;            /**< Connector write queue */
    void            *context;               /**< Embedding context (EjsRequest) */
    void            *ejs;                   /**< Embedding VM */
    void            *pool;                  /**< Pool of VMs */
    void            *mark;                  /**< Reference for GC marking */
    void            *data;                  /**< Custom data for request */
    void            *grid;                  /**< Current request database grid for MVC apps */
    void            *record;                /**< Current request database record for MVC apps */
    char            *boundary;              /**< File upload boundary */
    char            *errorMsg;              /**< Error message for the last request (if any) */
    char            *ip;                    /**< Remote client IP address */
    char            *protocol;              /**< HTTP protocol */
    char            *protocols;             /**< Supported web socket protocols (clients) */
    int             async;                  /**< Connection is in async mode (non-blocking) */
    int             followRedirects;        /**< Follow redirects for client requests */
    int             keepAliveCount;         /**< Count of remaining Keep-Alive requests for this connection */
    int             http10;                 /**< Using legacy HTTP/1.0 */
    int             port;                   /**< Remote port */
    int             retries;                /**< Client request retries */
    int             secure;                 /**< Using https */
    int             seqno;                  /**< Unique connection sequence number */
    int             upgraded;               /**< Request protocol upgraded */
    int             worker;                 /**< Use worker */
    /*  
        Authentication
     */
    int             authRequested;          /**< Authorization requested based on user credentials */
    char            *authType;              /**< Type of authentication: set to basic, digest, post or a custom name */
    void            *authData;              /**< Authorization state data */
    char            *username;              /**< Supplied user name */
    char            *password;              /**< Supplied password (may be encrypted depending on auth protocol) */
    int             encoded;                /**< True if the password is MD5(username:realm:password) */
    struct HttpUser *user;                  /**< Authorized User record for access checking */
    void            *headersCallbackArg;    /**< Arg to fillHeaders */

} HttpConn;

typedef struct HttpTx {
    /* Ordered for debugging */
    int             finalized;              /**< Request response generated and handler processing is complete */
    int             pendingFinalize;        /**< Call httpFinalize again once the Tx pipeline is created */
    int             finalizedConnector;     /**< Connector has finished sending the response */
    int             finalizedOutput;        /**< Handler or surrogate has finished writing output response */
    char            *filename;              /**< Name of a real file being served (typically pathInfo mapped) */
    int             flags;                  /**< Response flags */
    int             status;                 /**< HTTP response status */
    int             responded;              /**< The request has started to respond. Some output has been initiated. */
    int             started;                /**< Handler has started */
    char            *etag;                  /**< Unique identifier tag */
    HttpStage       *handler;               /**< Final handler serving the request */
    int             writeBlocked;           /**< Transmission writing is blocked */
    char            *method;                /**< Client request method GET, HEAD, POST, DELETE, OPTIONS, PUT, TRACE */
    struct HttpConn *conn;                  /**< Current connection object */
    HttpStage       *connector;             /**< Network connector to send / receive socket data */
    HttpQueue       *queue[2];              /**< Pipeline queue heads */
    char            *rangeBoundary;         /**< Inter-range boundary */
    char            *altBody;               /**< Alternate transmission for errors */
    int             traceMethods;           /**< Handler methods supported */
    /* File information for file-based handlers */
    char            *webSockKey;            /**< Sec-WebSocket-Key header */
} HttpTx;
static void handleDeleteRequest(HttpQueue *q)
{
    HttpConn    *conn;	
    HttpTx      *tx;

    conn = q->conn;
    tx = conn->tx;

}

struct book{
	int num;
	float price;
	struct book*next;
};
void main()
{
	void*p=malloc(sizeof(book));

	

	free(p);

	system("pause");

};
