StringIntMap makeWordCounts(const StringVec& words) {

    StringIntMap wordcount_map;
    for (auto const &word :words)
    {
        ++wordcount_map[word];}
    return wordcount_map;
}

