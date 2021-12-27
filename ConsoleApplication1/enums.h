#pragma once
namespace LAB1 {
	enum class Keys {
		Exit = 48								// Key 0, Выход
		, GeneratingRandomArray				// Key 1
		, PrintArray						// Key 2
		, ClearArray						// Key 3
		, ResizeArray						// Key 4
		, ShuffleArray = 56					// Key 8
		, ShowSeries = 57						// Key 9
		, SortByDirectSelectionAsk = 122	// Key z
		, SortByDirectSelectionDesk = 120	// Key x
		, ShellSortAsk = 99					// Key c
		, ShellSortDesc = 118				// Key v
		, HoareSortAsk = 98					// Key b
		, HoareSortDesc = 110				// Key n
		,
	};

	enum class SortingStatus {
		SortedAscending, SortedDescending, ShuffleSorted, RandomSorted, NotStatus
	};
}




