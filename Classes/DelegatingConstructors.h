#pragma once

class ChainOrDelegateConstructorCalls {
private:
    float num {0.0f};
public:
    ChainOrDelegateConstructorCalls();
    ChainOrDelegateConstructorCalls(float changeVal);
    ChainOrDelegateConstructorCalls(float changeVal,float addDelta);
    float GetNum();
    float SetNum();
};