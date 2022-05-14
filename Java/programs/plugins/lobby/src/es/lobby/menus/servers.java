package es.lobby.menus;

import es.lobby.Util;
import es.lobby.config.Config;
import org.bukkit.Bukkit;
import org.bukkit.entity.Player;
import org.bukkit.event.inventory.InventoryClickEvent;
import org.bukkit.inventory.Inventory;
import org.bukkit.inventory.ItemStack;

public class servers {
    public static Inventory inv;
    public static String inv_name;
    public static int inv_rows = 3 * 9;

    public static void initalize() {
        inv_name = Util.color(Config.GetMenus().getString("menu_de_juegos.name"));

        inv = Bukkit.createInventory(null, inv_rows);
    }

    public static void openInv(Player p) {
        p.openInventory(getInv());
        return;
    }

    public static Inventory getInv() {
        Inventory toreturn = Bukkit.createInventory(null, inv_rows, inv_name);

        /*
            -------------------------
            1  2  3  4  5  6  7  8  9
            10 11 12 13 14 15 16 17 18
            19 20 21 22 23 24 25 26 27
            -------------------------
        */

        inv.setItem(Config.GetMenus().getInt("menu_de_juegos.kitpvp.slot") - 1, Util.createItem(Config.GetMenus().getString("menu_de_juegos.kitpvp.material"), 1, Config.GetMenus().getString("menu_de_juegos.kitpvp.displayName"), Config.GetMenus().getStringList("menu_de_juegos.kitpvp.description").toArray(new String[0])));

        toreturn.setContents(inv.getContents());

        return toreturn;
    }

    public static void clicked(Player p, int slot, ItemStack clicked, Inventory inv, InventoryClickEvent event) {
        if(clicked.getItemMeta().getDisplayName().equalsIgnoreCase(Util.color(Config.GetMenus().getString("menu_de_juegos.kitpvp.displayName")))) {
            p.sendMessage(Util.color("&cHi i'm test"));
        }
    }
}
