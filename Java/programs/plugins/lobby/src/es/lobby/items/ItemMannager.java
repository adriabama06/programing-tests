package es.lobby.items;

import es.lobby.Util;
import es.lobby.config.Config;
import es.lobby.menus.servers;
import org.bukkit.entity.Player;
import org.bukkit.event.player.PlayerInteractEvent;
import org.bukkit.inventory.ItemStack;

import java.util.ArrayList;

public class ItemMannager {
    public static ItemStack menu_de_juegos;

    public static void initalize() {
        menu_de_juegos = Util.createItem(Config.GetItems().getString("menu_de_juegos.material"), 1, Config.GetItems().getString("menu_de_juegos.displayName"), Config.GetItems().getStringList("menu_de_juegos.description").toArray(new String[0]));
    }

    public static void menu_de_juegosEvent(Player p, ItemStack item, PlayerInteractEvent event) {
        servers.openInv(p);
    }
}
