package es.lobby.items;

import es.lobby.Main;
import org.bukkit.entity.Player;
import org.bukkit.event.EventHandler;
import org.bukkit.event.Listener;
import org.bukkit.event.block.Action;
import org.bukkit.event.player.PlayerDropItemEvent;
import org.bukkit.event.player.PlayerInteractEvent;

public class ItemEvents implements Listener {
    private Main plugin;

    public ItemEvents(Main plugin) {
        this.plugin = plugin;

        plugin.getServer().getPluginManager().registerEvents(this, plugin);
    }

    @EventHandler
    public static void onRightClick(PlayerInteractEvent event) {
        if(event.getAction() == Action.RIGHT_CLICK_AIR || event.getAction() == Action.RIGHT_CLICK_BLOCK) {
            if(event.getItem() != null) {
                if(event.getItem().getItemMeta().equals(ItemMannager.menu_de_juegos.getItemMeta())) {
                    ItemMannager.menu_de_juegosEvent(event.getPlayer(), event.getItem(), event);
                }
            }
        }
    }
    @EventHandler
    public static void onItemDrop(PlayerDropItemEvent event) {
        if(!(event.getPlayer() == null)) {
            Player p = event.getPlayer();
            if (!p.hasPermission("lobby.invedit")) {
                event.setCancelled(true);
            }
        }
    }
}
