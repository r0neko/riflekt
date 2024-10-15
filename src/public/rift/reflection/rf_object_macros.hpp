#pragma once

// debug
#include <cstdio>

#define RF_ABS_OBJECT_PROTO(objName) \
    public: \
        virtual RFTypeInfo* getTypeInfo() const { return &objName##TypeInfo; } \
        static RFTypeInfo* getStaticTypeInfo() { return &objName##TypeInfo; } \
    protected: \
        inline static RFTypeInfo objName##TypeInfo{#objName, nullptr, nullptr}; \
    private: \
        inline static const bool Is##objName##Registered = []() { \
                printf("[REFLECTION DEBUG] Registering abstract object %s\n", #objName); \
                RFObject::getRegistry()[#objName] = &objName##TypeInfo; \
                return true; \
        }();

#define RF_OBJECT_PROTO(objName, baseName) \
    public: \
        static RFObject* createInstance() { return new objName(); }; \
        virtual RFTypeInfo* getTypeInfo() const { return &objName##TypeInfo; } \
        static RFTypeInfo* getStaticTypeInfo() { return &objName##TypeInfo; } \
    protected: \
        inline static RFTypeInfo objName##TypeInfo{#objName, &objName::createInstance, &baseName::baseName##TypeInfo}; \
    private: \
        inline static const bool Is##objName##Registered = []() { \
                printf("[REFLECTION DEBUG] Registering object %s\n", #objName); \
                RFObject::getRegistry()[#objName] = &objName##TypeInfo; \
                return true; \
        }();

#define RF_OBJECT_DECLARE(objName, baseName) \
    public: \
        using Super = baseName; \
        using ThisClass = objName; \
    RF_OBJECT_PROTO(objName, baseName) \
    public: