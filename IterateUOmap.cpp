int lookupWithFallback(const StringIntMap& wordcount_map, const std::string& key, int fallbackVal) {

    auto pos = wordcount_map.find(key);
    if (pos == wordcount_map.end())
        return fallbackVal;
    return pos->second;
}
