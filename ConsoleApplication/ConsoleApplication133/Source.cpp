#include <ctime>
#include <iostream>
#include <string>

typedef struct HttpQueue {

    struct HttpQueue    *scheduleNext;          /**< Next linkage when queue is on the service queue */
    struct HttpQueue    *schedulePrev;          /**< Previous linkage when queue is on the service queue */
    struct HttpQueue    *pair;                  /**< Queue for the same stage in the opposite direction */
    int                 servicing;              /**< Currently being serviced */
    int                 direction;              /**< Flow direction */
    void                *queueData;             /**< Stage instance data */

} HttpQueue;


typedef struct HttpStage {
    char            *name;                  /**< Stage name */
    char            *path;                  /**< Backing module path (from LoadModule) */
    int             flags;                  /**< Stage flags */
    void            *stageData;             /**< Private stage data */
    void (*start)(HttpQueue *q);
	
} HttpStage;
int main()
{

	system("pause");
        return 0;
}