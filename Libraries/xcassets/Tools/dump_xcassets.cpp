/* Copyright 2013-present Facebook. All Rights Reserved. */

#include <xcassets/Asset.h>
#include <xcassets/Catalog.h>
#include <xcassets/Group.h>

using xcassets::Asset;
using xcassets::Group;
using xcassets::Catalog;

static void
Print(std::string const &string, int indent)
{
    for (int i = 0; i < indent; ++i) {
        fprintf(stdout, "  ");
    }
    fprintf(stdout, "%s\n", string.c_str());
}

static void
DumpAsset(std::shared_ptr<Asset> const &asset, int indent = 0)
{
    Print("name: " + asset->name(), indent);
    Print("path: " + asset->path(), indent);
    if (asset->group()) {
        Print("group: " + *asset->group(), indent);
    } else {
        Print("group: <root>", indent);
    }
    Print("identifier: " + asset->identifier(), indent);

    if (asset->author()) {
        Print("author: " + *asset->author(), indent);
    }
    if (asset->version()) {
        Print("version: " + std::to_string(*asset->version()), indent);
    }

    if (asset->type() == Catalog::Type()) {
        auto catalog = std::static_pointer_cast<Catalog>(asset);
        Print("type: Catalog", indent);

        for (std::shared_ptr<Asset> const &child : catalog->children()) {
            Print("", indent);
            DumpAsset(child, indent + 1);
        }
    } else if (asset->type() == Group::Type()) {
        auto group = std::static_pointer_cast<Group>(asset);
        Print("type: Group", indent);

        if (group->onDemandResourceTags()) {
            Print("on-demand-asset-tags: " + std::to_string(group->onDemandResourceTags()->size()), indent);
        }
        Print("provides namespace: " + std::to_string(group->providesNamespace()), indent);

        for (std::shared_ptr<Asset> const &child : group->children()) {
            Print("", indent);
            DumpAsset(child, indent + 1);
        }
    } else {
        Print("unknown asset type", indent);
    }
}

int
main(int argc, char **argv)
{
    if (argc < 2) {
        fprintf(stderr, "error: missing input\n");
        return 1;
    }

    std::shared_ptr<Asset> asset = Asset::Load(argv[1], ext::nullopt);
    DumpAsset(asset);

    return 0;
}
