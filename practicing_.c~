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
  void (*operations[4])(void *, int, int);
  P_FLAG active_flags;
  
} Pipeline;

Pipeline create_pipeline(void *data, size_t size, size_t data_size, P_FLAG flags){

  Pipeline pipeline = { .size = size, .data_size = data_size, .active_flags = flags };

  size_t allocation_size = pipeline.size * pipeline.data_size;
  
  pipeline.data = malloc(allocation_size);
  memcpy(pipeline.data, data, sizeof(allocation_size));
  
  if(flags & P_MAP) pipeline.operations[0] = map_function;
  else pipeline.operations[0] = NULL;

  if(flags & P_REDUCE) pipeline.operations[1] = reduce_function;
  else pipeline.operations[1] = NULL;
  
  if(flags & P_SORT) pipeline.operations[2] = sort_function;
  else pipeline.operations[2] = NULL;
  
  if(flags & P_FILTER) pipeline.operations[3] = filter_function;
  else pipeline.operations[3] = NULL;

  return pipeline;
}

int pipeline_destroy(Pipeline *pipeline){
  if(pipeline != NULL){
    free(pipeline->data);
    pipeline->size = 0;
    pipeline->data_size=0;
    pipeline->operations = NULL;
    
    return 0;
  }
  
  return 1;
}

void pipeline_register(Pipeline *pipeline, P_FLAG flag, void (*operation)(void *, size_t, size_t)){
}

void pipeline_run(Pipeline *pipeline){
  
}

int main(void){

  
  
  return 0;
}
