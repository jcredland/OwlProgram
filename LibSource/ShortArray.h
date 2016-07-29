#ifndef __ShortArray_h__
#define __ShortArray_h__

#include <stdint.h>
#include "basicmaths.h"

/**
 * This class contains useful methods for manipulating arrays of int16_ts.
 * It also provides a convenient handle to the array pointer and the size of the array.
 * ShortArray objects can be passed by value without copying the contents of the array.
 */
class ShortArray {
private:
  int16_t* data;
  int size;
public:
  ShortArray();
  ShortArray(int16_t* data, int size);

  int getSize() const{
    return size;
  }

  int getSize(){
    return size;
  }

  /**
   * Clear the array.
   * Set all the values in the array to 0.
  */
  void clear(){
    setAll(0);
  }
  
  /**
   * Get the minimum value in the array and its index
   * @param[out] value will be set to the minimum value after the call
   * @param[out] index will be set to the index of the minimum value after the call
   * 
   */
  void getMin(int16_t* value, int* index);
  
  /**
   * Get the maximum value in the array and its index
   * @param[out] value will be set to the maximum value after the call
   * @param[out] index will be set to the index of the maximum value after the call
  */
  void getMax(int16_t* value, int* index);
  
  /**
   * Get the minimum value in the array
   * @return the minimum value contained in the array
  */
  int16_t getMinValue();
  
  /**
   * Get the maximum value in the array
   * @return the maximum value contained in the array
   */
  int16_t getMaxValue();
  
  /**
   * Get the index of the minimum value in the array
   * @return the mimimum value contained in the array
   */
  int getMinIndex();
  
  /**
   * Get the index of the maximum value in the array
   * @return the maximum value contained in the array
   */
  int getMaxIndex();
  
  int16_t getDb(); //TODO: not implemented
  
  /**
   * Absolute value of the array.
   * Stores the absolute value of the elements in the array into destination.
   * @param[out] destination the destination array.
  */
  void rectify(ShortArray& destination);
  
  /**
   * Absolute value of the array.
   * Sets each element in the array to its absolute value.
  */
  void rectify(); //in place
  
  /**
   * Reverse the array
   * Copies the elements of the array in reversed order into destination.
   * @param[out] destination the destination array.
  */
  void reverse(ShortArray& destination);
  
  /**
   * Reverse the array.
   * Reverses the order of the elements in the array.
  */
  void reverse(); //in place
  
  /**
   * Reciprocal of the array.
   * Stores the reciprocal of the elements in the array into destination.
   * @param[out] destination the destination array.
  */
  void reciprocal(ShortArray& destination);
  
  /**
   * Reciprocal of the array.
   * Sets each element in the array to its reciprocal.
  */
  void reciprocal(); 
  
  /**
   * Negate the array.
   * Stores the opposite of the elements in the array into destination.
   * @param[out] destination the destination array.
  */
  void negate(ShortArray& destination);
  
  /**
   * Negate the array.
   * Sets each element in the array to its opposite.
  */
  void negate(); 
  
  /**
   * Random values
   * Fills the array with random values in the range [-1, 1)
   */
  void noise();
  
  /**
   * Random values in range.
   * Fills the array with random values in the range [**min**, **max**)
   * @param min minimum value in the range
   * @param max maximum value in the range 
   */
  void noise(int16_t min, int16_t max);
  
  /**
   * Root mean square value of the array.
   * Gets the root mean square of the values in the array.
  */
  int16_t getRms();
  
  /**
   * Mean of the array.
   * Gets the mean (or average) of the values in the array.
  */
  int16_t getMean();
  
  /**
   * Power of the array.
   * Gets the power of the values in the array.
  */
  int64_t getPower();
  
  /**
   * Standard deviation of the array.
   * Gets the standard deviation of the values in the array.
  */
  int16_t getStandardDeviation();
  
  /**
   * Variance of the array.
   * Gets the variance of the values in the array.
  */
  int16_t getVariance();
  
  /**
   * Scales the content of the array by the given factor.
   *
   * @param factor is the fractional portion of the scale value, in 1.15 format
   * The input data *pSrc and scaleFract are in 1.15 format. 
   * These are multiplied to yield a 2.30 intermediate result and
   * this is shifted with saturation to 1.15 format.
   * @param shift the number of bits to shift the intermediate result by.
   * @param destination the output array
  */
  void scale(int16_t factor, int8_t shift, ShortArray destination);
  
  /**
   * Array by scalar multiplication, in-place.
   * @param[in] factor the scaling factor
  */
  void scale(int16_t factor, int8_t shift);
  
  /**
   * Clips the elements in the array in the range [-**range**, **range**].
   * @param range clipping value.
  */
  void clip(int16_t range);
  
  /**
   * Clips the elements in the array in the range [**min**, **max**].
   * @param min minimum value
   * @param max maximum value
  */
  void clip(int16_t min, int16_t max);
  
  /**
   * Element-wise sum between arrays.
   * Sets each element in **destination** to the sum of the corresponding element of the array and **operand2**
   * @param[in] operand2 second operand for the sum
   * @param[out] destination the destination array
  */
  void add(ShortArray operand2, ShortArray destination);
  
  /**
   * Element-wise sum between arrays.
   * Adds each element of **operand2** to the corresponding element in the array.
   * @param operand2 second operand for the sum
  */
  void add(ShortArray operand2); //in-place
  
  /**
   * Array-scalar sum.
   * Adds **scalar** to the values in the array.
   * @param scalar value to be added to the array
  */
  void add(int16_t scalar);
  
  /**
   * Element-wise difference between arrays.
   * Sets each element in **destination** to the difference between the corresponding element of the array and **operand2**
   * @param[in] operand2 second operand for the subtraction
   * @param[out] destination the destination array
  */
  void subtract(ShortArray operand2, ShortArray destination);
  
  
  /**
   * Element-wise difference between arrays.
   * Subtracts from each element of the array the corresponding element in **operand2**.
   * @param[in] operand2 second operand for the subtraction
  */
  void subtract(ShortArray operand2); //in-place
  
  /**
   * Array-scalar subtraction.
   * Subtracts **scalar** from the values in the array.
   * @param scalar to be subtracted from the array
  */
  void subtract(int16_t scalar);
  
/**
   * Element-wise multiplication between arrays.
   * Sets each element in **destination** to the product of the corresponding element of the array and **operand2**
   * @param[in] operand2 second operand for the product
   * @param[out] destination the destination array
  */
  void multiply(ShortArray operand2, ShortArray destination);
  
   /**
   * Element-wise multiplication between arrays.
   * Multiplies each element in the array by the corresponding element in **operand2**.
   * @param operand2 second operand for the sum
  */
  void multiply(ShortArray operand2); //in-place
  
  /**
   * Array-scalar multiplication.
   * Multiplies the values in the array by **scalar**.
   * @param scalar to be multiplied with the array elements
  */
  void multiply(int16_t scalar);
  
  /**
   * Convolution between arrays.
   * Sets **destination** to the result of the convolution between the array and **operand2**
   * @param[in] operand2 the second operand for the convolution
   * @param[out] destination array. It must have a minimum size of this+other-1.
  */
  void convolve(ShortArray operand2, ShortArray destination);
  
  /** 
   * Partial convolution between arrays.
   * Perform partial convolution: start at **offset** and compute **samples** values.
   * @param[in] operand2 the second operand for the convolution.
   * @param[out] destination the destination array.
   * @param[in] offset first output sample to compute
   * @param[in] samples number of samples to compute
   * @remarks **destination[n]** is left unchanged for n<offset and the result is stored from destination[offset] onwards
   * that is, in the same position where they would be if a full convolution was performed.
  */
  void convolve(ShortArray operand2, ShortArray destination, int offset, int samples);
  
  /** 
   * Correlation between arrays.
   * Sets **destination** to the correlation of the array and **operand2**.
   * @param[in] operand2 the second operand for the correlation
   * @param[out] destination the destination array. It must have a minimum size of 2*max(srcALen, srcBLen)-1
  */
  void correlate(ShortArray operand2, ShortArray destination);
  
  /**
   * Correlation between arrays.
   * Sets **destination** to the correlation of *this* array and **operand2**.
   * @param[in] operand2 the second operand for the correlation
   * @param[out] destination array. It must have a minimum size of 2*max(srcALen, srcBLen)-1
   * @remarks It is the same as correlate(), but destination must have been initialized to 0 in advance. 
  */
  void correlateInitialized(ShortArray operand2, ShortArray destination);

  /**
   * Set all the values in the array.
   * Sets all the elements of the array to **value**.
   * @param[in] value all the elements are set to this value.
  */
  void setAll(int16_t value);
  
  /**
   * A subset of the array.
   * Returns a array that points to subset of the memory used by the original array.
   * @param[in] offset the first element of the subset.
   * @param[in] length the number of elments in the new ShortArray.
   * @return the newly created ShortArray.
   * @remarks no memory is allocated by this method. The memory is still shared with the original array.
   * The memory should not be de-allocated elsewhere (e.g.: by calling ShortArray::destroy() on the original ShortArray) 
   * as long as the ShortArray returned by this method is still in use.
   * @remarks Calling ShortArray::destroy() on a ShortArray instance created with this method might cause an exception.
  */
  ShortArray subArray(int offset, int length);
  
  /**
   * Copies the content of the array to another array.
   * @param[out] destination the destination array
  */
  void copyTo(ShortArray destination);

  /**
   * Copies the content of the array to a location in memory.
   * @param[out] destination a pointer to the beginning of the memory location to copy to.
   * The **length***sizeof(int16_t) bytes of memory starting at this location must have been allocated before calling this method.
   * @param[in] length number of samples to copy
  */
  void copyTo(int16_t* destination, int length);

  /**
   * Copies the content of an array into another array.
   * @param[in] source the source array
  */
  void copyFrom(ShortArray source);
  
  /**
   * Copies an array of int16_t into the array.
   * @param[in] source a pointer to the beginning of the portion of memory to read from.
   * @param[in] length number of samples to copy.
  */
  void copyFrom(int16_t* source, int length);
  
  /**
   * Copies the content of an array into a subset of the array.
   * Copies **samples** elements from **source** to **destinationOffset** in the current array.
   * @param[in] source the source array
   * @param[in] destinationOffset the offset into the destination array 
   * @param[in] samples the number of samples to copy
   *
  */
  void insert(ShortArray source, int destinationOffset, int samples);

  /**
   * Copies the content of an array into a subset of the array.
   * Copies **samples** elements starting from **sourceOffset** of **source** to **destinationOffset** in the current array.
   * @param[in] source the source array
   * @param[in] sourceOffset the offset into the source array
   * @param[in] destinationOffset the offset into the destination array
   * @param[in] samples the number of samples to copy
  */
  void insert(ShortArray source, int sourceOffset, int destinationOffset, int samples);
  
  /**
   * Copies values within an array.
   * Copies **length** values starting from index **fromIndex** to locations starting with index **toIndex**
   * @param[in] fromIndex the first element to copy
   * @param[in] toIndex the destination of the first element
   * @param[in] length the number of elements to copy
   * @remarks this method uses *memmove()* so that the source memory and the destination memory can overlap. As a consequence it might have slow performances.
  */
  void move(int fromIndex, int toIndex, int length);
  
  /**
   * Allows to index the array using array-style brackets.
   * @param index the index of the element
   * @return the value of the **index** element of the array
   * Example usage:
   * @code
   * int size=1000;
   * int16_t content[size]; 
   * ShortArray int16_tArray(content, size);
   * for(int n=0; n<size; n++)
   *   content[n]==int16_tArray[n]; //now the ShortArray can be indexed as if it was an array
   * @endcode
  */
  int16_t& operator [](const int index){
    return data[index];
  }
  
  /**
   * Allows to index the array using array-style brackets.
   * **const** version of operator[]
  */
  int16_t& operator [](const int index) const{
    return data[index];
  }
  
  /**
   * Compares two arrays.
   * Performs an element-wise comparison of the values contained in the arrays.
   * @param other the array to compare against.
   * @return **true** if the arrays have the same size and the value of each of the elements of the one 
   * match the value of the corresponding element of the other, or **false** otherwise.
  */
  bool equals(const ShortArray& other) const{
    if(size!=other.getSize()){
      return false;
    }
    for(int n=0; n<size; n++){
      if(data[n]!=other[n]){
        return false;
      }
    }
    return true;
  }
  
  /**
   * Casting operator to int16_t*
   * @return a int16_t* pointer to the data stored in the ShortArray
  */
  operator int16_t*(){
    return data;
  }
  
  /**
   * Get the data stored in the ShortArray.
   * @return a int16_t* pointer to the data stored in the ShortArray
  */
  int16_t* getData(){
    return data;
  }
  
  /**
   * Bitshift the array values, saturating.
   *
   * @param shiftValue number of positions to shift. A positive value will shift left, a negative value will shift right.
   */
  void shift(int shiftValue);

  /**
   * Creates a new ShortArray.
   * Allocates size*sizeof(int16_t) bytes of memory and returns a ShortArray that points to it.
   * @param size the size of the new ShortArray.
   * @return a ShortArray which **data** point to the newly allocated memory and **size** is initialized to the proper value.
   * @remarks a ShortArray created with this method has to be destroyed invoking the ShortArray::destroy() method.
  */
  static ShortArray create(int size);
  
  /**
   * Destroys a ShortArray created with the create() method.
   * @param array the ShortArray to be destroyed.
   * @remarks the ShortArray object passed as an argument should not be used again after invoking this method.
   * @remarks a ShortArray object that has not been created by the ShortArray::create() method might cause an exception if passed as an argument to this method.
  */
  static void destroy(ShortArray array);
};


class IntArray {
private:
  int32_t* data;
  int size;
public:
  IntArray();
  IntArray(int32_t* data, int size);

  int getSize() const{
    return size;
  }

  int getSize(){
    return size;
  }

  void setAll(int32_t value){
  /// @note When built for ARM Cortex-M processor series, this method uses the optimized <a href="http://www.keil.com/pack/doc/CMSIS/General/html/index.html">CMSIS library</a>
  #ifdef ARM_CORTEX
    arm_fill_q31(value, data, size);
  #else
    for(int n=0; n<size; n++){
      data[n]=value;
    }
  #endif /* ARM_CORTEX */
  }

  /**
   * Clear the array.
   * Set all the values in the array to 0.
  */
  void clear(){
    setAll(0);
  }
  
  /**
   * Element-wise sum between arrays.
   * Sets each element in **destination** to the sum of the corresponding element of the array and **operand2**
   * @param[in] operand2 second operand for the sum
   * @param[out] destination the destination array
  */
  void add(IntArray operand2, IntArray destination){ //allows in-place
    //ASSERT(operand2.size >= size &&  destination.size<=size, "Arrays must be matching size");
  /// @note When built for ARM Cortex-M processor series, this method uses the optimized <a href="http://www.keil.com/pack/doc/CMSIS/General/html/index.html">CMSIS library</a>
  #ifdef ARM_CORTEX
    arm_add_q31(data, operand2.data, destination.data, size);
  #else
    for(int n=0; n<size; n++){
      destination[n]=data[n]+operand2[n];
    }
  #endif /* ARM_CORTEX */
}
  
  /**
   * Element-wise sum between arrays.
   * Adds each element of **operand2** to the corresponding element in the array.
   * @param operand2 second operand for the sum
  */
  void add(IntArray operand2){ //in-place
  /// @note When built for ARM Cortex-M processor series, this method uses the optimized <a href="http://www.keil.com/pack/doc/CMSIS/General/html/index.html">CMSIS library</a>
    add(operand2, *this);
  } //in-place
  
  /**
   * Allows to index the array using array-style brackets.
   * @param index the index of the element
   * @return the value of the **index** element of the array
   * Example usage:
   * @code
   * int size=1000;
   * int32_t content[size]; 
   * IntArray intArray(content, size);
   * for(int n=0; n<size; n++)
   *   content[n]==intArray[n]; //now the IntArray can be indexed as if it was an array
   * @endcode
  */
  int32_t& operator [](const int index){
    return data[index];
  }
  
  /**
   * Allows to index the array using array-style brackets.
   * **const** version of operator[]
  */
  int32_t& operator [](const int index) const{
    return data[index];
  }
  
  /**
   * Compares two arrays.
   * Performs an element-wise comparison of the values contained in the arrays.
   * @param other the array to compare against.
   * @return **true** if the arrays have the same size and the value of each of the elements of the one 
   * match the value of the corresponding element of the other, or **false** otherwise.
  */
  bool equals(const IntArray& other) const{
    if(size!=other.getSize()){
      return false;
    }
    for(int n=0; n<size; n++){
      if(data[n]!=other[n]){
        return false;
      }
    }
    return true;
  }
  
  /**
   * Casting operator to int32_t*
   * @return a int32_t* pointer to the data stored in the IntArray
  */
  operator int32_t*(){
    return data;
  }
  
  /**
   * Get the data stored in the IntArray.
   * @return a int32_t* pointer to the data stored in the IntArray
  */
  int32_t* getData(){
    return data;
  }
  
  /**
   * Creates a new IntArray.
   * Allocates size*sizeof(int32_t) bytes of memory and returns a IntArray that points to it.
   * @param size the size of the new IntArray.
   * @return a IntArray which **data** point to the newly allocated memory and **size** is initialized to the proper value.
   * @remarks a IntArray created with this method has to be destroyed invoking the IntArray::destroy() method.
  */
  static IntArray create(int size){
    IntArray fa(new int32_t[size], size);
    fa.clear();
    return fa;
  }
  
  /**
   * Destroys a IntArray created with the create() method.
   * @param array the IntArray to be destroyed.
   * @remarks the IntArray object passed as an argument should not be used again after invoking this method.
   * @remarks a IntArray object that has not been created by the IntArray::create() method might cause an exception if passed as an argument to this method.
  */
  static void destroy(IntArray array){
    delete array.data;
  }

  /**
   * Bitshift the array values, saturating.
   *
   * @param shiftValue number of positions to shift. A positive value will shift left, a negative value will shift right.
   */
  void shift(int shiftValue){
#ifdef ARM_CORTEX
    arm_shift_q31(data, shiftValue, data, size);
#else
    if(shiftValue > 0)
      for(int n=0; n<size; n++)
	data[n] <<= shiftValue;
    else
      for(int n=0; n<size; n++)
	data[n] >>= -shiftValue;
#endif
  }
};
#endif // __ShortArray_h__