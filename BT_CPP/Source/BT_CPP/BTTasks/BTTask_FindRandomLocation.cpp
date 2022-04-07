#include "BTTask_FindRandomLocation.h"

#include "AIController.h"
#include "NavigationSystem.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"

UBTTask_FindRandomLocation::UBTTask_FindRandomLocation(const FObjectInitializer& ObjectInitializer) :
	Super(ObjectInitializer)
{
	bNotifyTick = true;
	NodeName = "Find random location";

	Location.AddVectorFilter(this, GET_MEMBER_NAME_CHECKED(UBTTask_FindRandomLocation, Location));
}

EBTNodeResult::Type UBTTask_FindRandomLocation::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	if (UBlackboardComponent* BlackboardComponent = OwnerComp.GetBlackboardComponent())
	{
		if (const AAIController* Controller = OwnerComp.GetAIOwner())
		{
			FVector NewLocation = UNavigationSystemV1::GetRandomPointInNavigableRadius(
				GetWorld(), Controller->GetPawn()->GetActorLocation(),
				Radius);
			BlackboardComponent->SetValueAsVector(Location.SelectedKeyName, NewLocation);
			return EBTNodeResult::Succeeded;
		}
	}
	return EBTNodeResult::Failed;
}
