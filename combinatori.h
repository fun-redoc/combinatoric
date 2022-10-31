#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>
#ifndef __COMBINATORIC_H__
#define __COMBINATORIC_H__
/************************************************
* USAGE
* 1. include as header file
* 2. define COMBINTATORIC_IMPL for implementation
************************************************/

/* headers */

/* combination iterator
 * iterates over all combinations of values (value indices) in a dims dimensional vector
 */
typedef struct combinatoric_combination_iterator_internal_s combinatoric_combination_iterator_t;
combinatoric_combination_iterator_t combinatoric_combination_iterator(size_t vals, size_t dims, size_t buffer[]);
bool combinatoric_combination_iterator_next(combinatoric_combination_iterator_t *iter, size_t *next);

#ifdef COMBINTATORIC_IMPL
#define COMBINTATORIC_IMPL_LEN(a) (sizeof(a)/sizeof(a[0]))
#define COMBINTATORIC_IMPL_EXIT(a, l, f) {fprintf(stderr, "%s in line %d of %s",a, l, f); exit(1);}

/* implementations */
struct combinatoric_combination_iterator_internal_s {
  size_t* cur;
  size_t vals;
  size_t dims;
  size_t idim;
  size_t ival;
};
combinatoric_combination_iterator_t combinatoric_combination_iterator(size_t vals, size_t dims, size_t cur[])
{
  //if(COMBINTATORIC_IMPL_LEN(cur) != dims) COMBINTATORIC_IMPL_EXIT("\"next\" param has not appriopriate dimension", __LINE__, __FILE__);
  memset(cur, 0, sizeof(size_t)*dims);
  combinatoric_combination_iterator_t res = {cur, vals, dims,0,0};
  //res.vals = vals;
  //res.dims = dims;
  //res.idim = 0;
  //res.ival = 0;
  return res;
}
bool combinatoric_combination_iterator_next(combinatoric_combination_iterator_t *iter, size_t *next)
{
  if(!iter->cur) COMBINTATORIC_IMPL_EXIT("\"cur\" buffer not provided",__LINE__, __FILE__);
  if(!next) COMBINTATORIC_IMPL_EXIT("\"cur\" param not provided",__LINE__, __FILE__);
  if(!iter) return false;
  //if(COMBINTATORIC_IMPL_LEN(next) != iter->dims) COMBINTATORIC_IMPL_EXIT("\"next\" param has not appriopriate dimension", __LINE__, __FILE__);
  if(iter->idim >= iter->dims) return false;

  memcpy(next, iter->cur, sizeof(size_t)*iter->dims);
  
  for(iter->idim=0; iter->idim<iter->dims; iter->idim++)
  {
    assert(iter->cur[iter->idim] >=0 && iter->cur[iter->idim] < iter->vals);

    iter->cur[iter->idim]++;
    iter->cur[iter->idim] %= iter->vals;

    if(iter->cur[iter->idim] != 0) 
    {
        break;
    }
    else
    {
      // overflow to next dim
      iter->cur[iter->idim] = 0;
    }
  }
  return true;
}
#endif
#endif
