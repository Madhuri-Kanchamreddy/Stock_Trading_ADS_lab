#include <stdint.h>
#include <assert.h>
#include "stock.h"

TradingQ initialise_q(){
    TradingQ q = {NULL, NULL, 0};
    return q;
}

Transaction initialise_transaction(){
    Transaction t = {NULL, NULL};
    return t;
}

static TradingNode* _get_new_tradingnode_(char share_name[], float price, char date[], int32_t quantity){
    TradingNode *newnode = (TradingNode*)malloc(sizeof(TradingNode));
    strcpy(newnode->share_name, share_name);
    newnode->price = price * quantity;
    strcpy(newnode->date, date);
    newnode->quantity = quantity;
    newnode->next = NULL;
    return newnode;
}

static TNode* _get_new_transactionnode_(char date[], char company_name[], int32_t quantity, float price, char status[]){
    TNode *newnode = (TNode*)malloc(sizeof(TNode));
    strcpy(newnode->date, date);
    strcpy(newnode->company_name, company_name);
    newnode->quantity = quantity;
    newnode->price = price;
    strcpy(newnode->status, status);
    newnode->next = NULL;
    return newnode;
}

TradingQ* buy_share(TradingQ *q, char share_name[], float price, char date[], int32_t quantity){
    assert(q!=NULL);
    TradingNode *node;
    if(q->front == NULL){
        TradingNode *newnode = _get_new_tradingnode_(share_name, price, date, quantity);
        q->front = newnode;
        q->rear = newnode;
        q->rear->next = q->front;
        ++q->count;
    }
    else if(q->count <= 5){
        node = q->front;
        while(node->next != q->front){
            if(!strcmp(node->share_name, share_name)){
                node->quantity = node->quantity + quantity;
                node->date = date;
                break;
            }
            else
                node = node->next;
        }
        if(tradingq_lookup(share_name) == 0){
            TradingNode *newnode = _get_new_tradingnode_(share_name, price, date, quantity);
            q->rear->next = newnode;
            q->rear = newnode;
            q->rear->next = q->front;
            ++q->count;
        }
    }
    return q;
}

TradingQ* topuop_shares(TradingQ *q, char share_name[], int32_t quantity){
    assert(q!=NULL);
    TradingNode *node = q->front;
    while(node->next != q->front){
        if(!strcmp(node->share_name, share_name)){
            node->quantity = node->quantity + quantity;
            node->date = date;
            break;
        }
        else
            node = node->next;
    }
    return q;
}

Transaction* share_transaction(Transaction *trans, char date[], char company_name[], int32_t quantity, float price, char status[]){
    assert(trans != NULL);
    TNode *newnode = _get_new_transactionnode_(date, company_name, quantity, price, status);
    if(trans->head == NULL && trans->tail == NULL){
        trans->head = newnode;
        trans->tail = newnode;
        ++trans->length;
    }
    else{
        trans->tail->next = newnode;
        trans->tail = newnode;
        ++trans->length;
    }
    return trans;
}

TradingNode* tradingq_lookup(TradingQ *q, char share_name[]){
    assert(q!=NULL);
    TradingNode *node = q->front;
    while(node->next != q->front){
        if(!strcmp(node->share_name, share_name))
            return node;
        else
            node = node->next;
    }
    return NULL;
}

TradingQ* sell_shares(TradingQ *q, int32_t quantity)
