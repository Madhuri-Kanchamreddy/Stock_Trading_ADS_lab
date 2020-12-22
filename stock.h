#include <stdint.h>
#ifndef STOCK_H_INCLUDED
#define STOCK_H_INCLUDED

#define NAME_LENGTH 20

typedef struct _transnode_ TNode;

struct _node_{
    char date[10];
    char company_name[NAME_LENGTH];
    int32_t quantity;
    float price;
    char status[4];
    Node *next;
};

typedef struct _tradingnode_ TradingNode;

struct _tradingnode_{
    char share_name[NAME_LENGTH];
    float price;
    char date[10];
    int32_t quantity;
    TradingNode *next;
};
typedef struct _tradingQ_ TradingQ;

struct _tradingQ_{
    TradingNode *front;
    TradingNode *rear;
    int32_t count;
};

typedef struct _tlist_ Transaction;

struct _tlist_{
    Node *head;
    Node *tail;
};

TradingQ initialise_q();
Transaction initialise_transaction();
TradingQ* buy_share(TradingQ *q,Transaction *trans, char share_name[], float price, char date[], int32_t quantity);
Transaction* share_transaction(Transaction *trans, char date[], char company_name[], int32_t quantity, float price, char status[]);
int32_t tradingq_lookup(TradingQ *q, char share_name[]);
TradingQ* topuop_shares(TradingQ *q, char share_name[], int32_t quantity);

#endif // STOCK_H_INCLUDED
