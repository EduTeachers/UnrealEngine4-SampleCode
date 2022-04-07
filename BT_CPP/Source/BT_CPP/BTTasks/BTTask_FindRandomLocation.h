#pragma once
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"

#include "BTTask_FindRandomLocation.generated.h"

UCLASS()
class UBTTask_FindRandomLocation : public UBTTask_BlackboardBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	FBlackboardKeySelector Location;
	
	UPROPERTY(EditAnywhere)
	int Radius = 2000;

	UBTTask_FindRandomLocation(const FObjectInitializer& ObjectInitializer);

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
};
