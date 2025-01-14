#include "GangActor.h"
#include "Math/UnrealMathUtility.h"

AGangActor::AGangActor()
{
    // 이 액터가 매 프레임 Tick()을 호출하도록 설정
    PrimaryActorTick.bCanEverTick = true;

    // 초기 위치를 (0,0,0)으로 설정
    CurrentPosition = FVector(0.0f, 0.0f, 0.0f);

    // 이동 횟수를 0으로 초기화
    MoveCount = 0;
}

void AGangActor::BeginPlay()
{
    Super::BeginPlay();

    // 게임 시작 시 이동 함수 호출
    Move();
}

// Called every frame
void AGangActor::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    // 현재는 Tick에서 별도의 동작이 필요하지 않음
}

// Step 함수 구현: x와 y를 각각 0 또는 1로 랜덤 결정
FVector AGangActor::Step()
{
    int32 StepX = FMath::RandRange(0, 1);
    int32 StepY = FMath::RandRange(0, 1);
    return FVector(StepX, StepY, 0.0f);
}

// Move 함수 구현: 10회 랜덤 이동 및 로그 출력
void AGangActor::Move()
{
    for (MoveCount = 1; MoveCount <= 10; MoveCount++)
    {
        // Step 함수를 통해 이동 거리 결정
        FVector MoveStep = Step();

        // 현재 위치 업데이트
        CurrentPosition += MoveStep;

        // 현재 위치를 로그로 출력
        UE_LOG(LogTemp, Warning, TEXT("Step %d: 현재 위치 (%f, %f)"), MoveCount, CurrentPosition.X, CurrentPosition.Y);
    }
}

