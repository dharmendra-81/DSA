> 69

**Given a non-negative integer `x`, return _the square root of_ `x` _rounded down to the nearest integer_. The returned integer should be non-negative as well.**

```cpp
class Solution { 
public: 
int mySqrt(long int x) { 
unsigned int i=0; 
while(i*i<=x){ 
if(i*i==x){ 
return i; 
} 
else{ 
i++; 
} 
} 
return i-1; 
} 
};
```



