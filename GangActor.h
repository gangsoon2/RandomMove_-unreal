

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GangActor.generated.h"

UCLASS()
class TEST_API AGangActor : public AActor
{
    GENERATED_BODY()

public:

    AGangActor();

protected:

    virtual void BeginPlay() override;

public:

    virtual void Tick(float DeltaTime) override;

private:
    // 현재 위치를 저장하는 변수
    FVector CurrentPosition;

    // 이동 횟수를 저장하는 변수
    int32 MoveCount;

    // 랜덤으로 x와 y 이동 거리를 반환하는 함수
    FVector Step();

    // 10회 이동을 처리하는 함수
    void Move();
};
