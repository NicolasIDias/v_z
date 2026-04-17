#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

//typedef int(*max)(int, int);

typedef unsigned int P_FLAG;
#define P_MAP (1 << 0)
#define P_REDUCE (1 << 1)
#define P_SORT (1 << 2)
#define P_FILTER (1 << 3)

typedef void (*operation)(void *, size_t, size_t);

typedef struct pipeline_t {

  void *data;
  size_t size, data_size;
  void (*operations[4])(void *, size_t, size_t);
  P_FLAG active_flags;
  
} Pipeline;


void map_function(void *data, size_t size, size_t data_size){
  for(size_t i=0;i<size;i++){}
}
void reduce_function(void *data, size_t size, size_t data_size){
  for(size_t i=0;i<size;i++){}
}
void sort_function(void *data, size_t size, size_t data_size){
  for(size_t i=0;i<size;i++){
    for(size_t j=i+1;j<size;j++){}
  }
}
void filter_function(void *data, size_t size, size_t data_size){
  for(size_t i=0;i<size;i++){}
}

void pipeline_register(Pipeline *pipeline, P_FLAG flags){
  
  for(size_t i=0;i<4;i++){
    if(flags & P_MAP) pipeline->operations[i] = map_function;
    else pipeline->operations[i] = NULL;

    if(flags & P_REDUCE) pipeline->operations[i] = reduce_function;
    else pipeline->operations[i] = NULL;

    if(flags & P_SORT) pipeline->operations[i] = sort_function;
    else pipeline->operations[i] = NULL;

    if(flags & P_FILTER) pipeline->operations[i] = filter_function;
    else pipeline->operations[i] = NULL;  
  }
 
}

Pipeline create_pipeline(void *data, size_t size, size_t data_size, P_FLAG flags){

  Pipeline pipeline = { .size = size, .data_size = data_size, .active_flags = flags };

  size_t allocation_size = pipeline.size * pipeline.data_size;
  
  pipeline.data = malloc(allocation_size);
  memcpy(pipeline.data, data, allocation_size);

  pipeline_register(&pipeline, flags); 
  
  return pipeline;
}

int pipeline_destroy(Pipeline *pipeline){
  if(pipeline != NULL){
    free(pipeline->data);
    pipeline->size = 0;
    pipeline->data_size=0;

    for (int i = 0; i < 4; i++)
      pipeline->operations[i] = NULL;
    
    return 0;
  }
  
  return 1;
}




void pipeline_run(Pipeline *pipeline){
  
}

int main(void){

  int xs[5] = { 1, 2, 3, 4, 5 };
  
  Pipeline t = create_pipeline(xs, sizeof(xs)/sizeof(xs[0]), sizeof(xs[0]), P_FILTER | P_SORT);
  
  
  return 0;
}
